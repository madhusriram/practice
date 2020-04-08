// Package luhn validates a credit card
package luhn

import (
	"unicode"
)

// Reverse reverse a string
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
	var digits int

	// single digit strings not valid
	if l == 1 {
		return false
	}

	var num int = 0
	cc = Reverse(cc)

	for _, d := range cc {
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
		case unicode.IsSpace(d):
			continue
		default:
			return false
		}
	}

	// case 1: single 0 is invalid
	// case 2: number not divisible by 10 not valid
	// this won't be caught in the length check earlier if the string has a
	// space and a 0 like " 0"
	if (num == 0 && digits == 1) || (num % 10 != 0) {
		return false	
	}

	return true
}

