// Package cryptosquare composes secret messages called a square code
package cryptosquare

import (
	"unicode"
)

// normalize removes spaces and punctuations and the message is downcased
func normalize(input string) string {
	var out string

	for _, c := range input {
		if unicode.IsDigit(c) {
			out += string(c)
		} else if unicode.IsLower(c) {
			out += string(c)
		} else if unicode.IsUpper(c) {
			out += string(unicode.ToLower(c))
		}
	}
	return out
}

// Encode encodes a string after normalizing
func Encode(input string) string {
	normalizedString  := normalize(input)


}
