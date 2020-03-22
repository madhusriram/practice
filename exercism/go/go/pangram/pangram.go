// Package pangram detects if a sentence is a pangram 
package pangram

import "unicode"

// IsPangram returns true if a sentence is a pangram
// else returns false
func IsPangram(input string) bool {
	if input == "" {
		return false
	}
	
	var mask uint32 = 0

	for _, c := range input {
		if !unicode.IsLetter(c) {
			continue
		}
	
		// 0011 1111 1111 1111 1111 1111 1111 == 2FFFFFF
		c = unicode.ToLower(c)
		placesToShift := uint32((int(c) - 97))
		mask |= (1 << placesToShift)
	}

	if mask & 0x3FFFFFF == 0x3FFFFFF {
		return true
	}
	return false
}
