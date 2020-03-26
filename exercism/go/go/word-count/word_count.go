package wordcount

import "strings"
import "unicode"
//import "fmt"

// Frequency maps words to their occurrences
type Frequency map[string]int

// What constitus a word?
// Anything that is a letter, or a apostrophe, or a number
func WordCount(input string) Frequency {
	var f Frequency = make(Frequency)

	var s strings.Builder
	var apostropheFound bool = false

	for _, c := range input {
		if unicode.IsLetter(c) || unicode.IsNumber(c) || c == '\'' {
			// start of the word can only be a number or a letter
			if s.Len() == 0 && c == '\'' {
				continue
			}
			// if we got an apostrophe then it might be at the end, make sure
			// we don't include that in the word
			if c == '\'' {
				apostropheFound = true
				continue
			}
			// if an apostrophe was read in the previous read then add it now
			// along with the current character
			if apostropheFound {
				s.WriteRune('\'')
				apostropheFound = false
			}
			s.WriteRune(unicode.ToLower(c))
		} else {
			// get string and store in map
			if s.Len() > 0 {
				f[s.String()] += 1
				apostropheFound = false
				s.Reset()
			}
		}
	}

	// last word
	if s.Len() > 0 {
		f[s.String()] += 1
	}

	return f
}
