package wordcount

import "strings"
import "unicode"

// Frequency maps words to their occurrences
type Frequency map[string]int

// What constitus a word?
// Anything that is a letter, or a apostrophe, or a number
func WordCount(input string) Frequency {
	var f Frequency = make(Frequency)

	var s strings.Builder

	for _, c := range input {
		if unicode.IsLetter(c) || unicode.IsNumber(c) || c == '\'' {
			s.WriteRune(unicode.ToLower(c))
		} else {
			// get string and store in map
			if s.Len() > 0 {
				// trim all leading and trailing '
				var res string = strings.Trim(s.String(), string('\''))
				f[res]++
				s.Reset()
			}
		}
	}

	// last word
	if s.Len() > 0 {
		var res string = strings.Trim(s.String(), string('\''))
		f[res] += 1
	}

	return f
}
