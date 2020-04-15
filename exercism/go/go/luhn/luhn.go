// Package luhn validates a credit card
package luhn

import (
	"unicode"
	"strings"
)

// RemoveSpaces removes spaces from a string
func RemoveSpaces(str string) string {
    var b strings.Builder
    b.Grow(len(str))
    for _, ch := range str {
        if !unicode.IsSpace(ch) {
            b.WriteRune(ch)
        }
    }
    return b.String()
}

// Valid returns true if a credit card number is valid
func Valid(cc string) bool {
	var digits int

	spacelessCc := RemoveSpaces(cc)
	l := len(spacelessCc)
	
	// single digit strings not valid
	if l == 1 {
		return false
	}

	// based on the digit count we start at the
	// first or second digit from the left to
	// do the multiply by 2 logic
	var double bool = false
	if l%2 == 0 {
		double = true
	}

	// accrue sum
	var num int = 0

	for _, d := range spacelessCc {
		switch {
		case unicode.IsNumber(d):
			digits++
			n := int(d - '0')
			if double {
				temp := n * 2
				if temp > 9 {
					temp -= 9
				}
				num += temp
				double = false
			} else {
				num += n
				double = true
			}
		default:
			return false
		}
	}

	// case 1: single 0 is invalid
	// case 2: number not divisible by 10 not valid
	// this won't be caught in the length check earlier if the string has a
	// space and a 0 like " 0"
	if (num == 0 && digits == 1) || (num%10 != 0) {
		return false
	}

	return true
}
