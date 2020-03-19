// Package isogram finds out if a string is a isogram
package isogram

import (
	"unicode"
)

// IsIsogram returns true if a string is a isogram
// else false
func IsIsogram(s string) bool {
	var mask uint32

	for _, c := range s {
		if ok := unicode.IsLetter(c); !ok {
			continue
		}
		l := unicode.ToLower(c)
		bit := uint32(1 << uint32(int(l)-97))

		// check if bit is already set, if not set it
		if mask&bit == bit {
			return false
		}
		mask |= bit
	}
	return true
}
