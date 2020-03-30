// Package isogram finds out if a string is a isogram
package isogram

import (
	"unicode"
)

// IsIsogram returns true if a string is a isogram
// else false
func IsIsogram(s string) bool {
	charMap := make(map[rune]bool)

	for _, c := range s {
		if ok := unicode.IsLetter(c); !ok {
			continue
		}
		c = unicode.ToUpper(c)
		// if character read before, exit
		if charMap[c] {
			return false
		}
		charMap[c] = true
	}
	return true
}
