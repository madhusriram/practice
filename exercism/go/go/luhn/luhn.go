// Package luhn validates a credit card
package luhn

import (
	"unicode"
)

func Reverse(cc string) string {
    runes := []rune(cc)
    for i, j := 0, len(runes)-1; i < j; {
        runes[i], runes[j] = runes[j], runes[i]
		i, j = i+1, j-1
    }
    return string(runes)
}

// Valid returns true if a credit card number is valid
func Valid(cc string) bool {
	l := len(cc)
	// double lets us know when to double 
	var double bool = false
	// single digit strings not valid
	if l == 1 {
		return false
	}

	var num int = 0
	cc = Reverse(cc)

	for _, d := range cc {
		if unicode.IsNumber(d) {
			n := int(d - '0')
			if double {
				num += (n * 2) % 9
				double = false
			} else {
				num += n
				double = true
			}
		} else if unicode.IsSpace(d) {
			continue
		} else {
			return false
		}
	}

	// if the number is evenly divisibly by 10 it's a valid credit card
	if num % 10 != 0 || num == 0 {
		return false
	}
	return true
}

