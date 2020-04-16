// Package luhn validates a credit card
package luhn

import (
	"unicode"
	"strings"
)

// Valid returns true if a credit card number is valid
func Valid(cc string) bool {
	var digits int

	newCc := strings.ReplaceAll(cc, " ","")
	lengthCc := len(newCc)
	
	// single digit strings not valid
	if lengthCc == 1 {
		return false
	}

	// accrue sum
	var num int = 0

	// start reading card from the left to right
	for i := lengthCc; i > 0; i-- {
		d := newCc[i-1]

		if !unicode.IsNumber(rune(d)) {
			return false
		}

		digits++
		n := int(d - '0')
	
		// odd positions go through the doubling and subtracting by 9 logic
		if (lengthCc-i)%2 != 0 {
			n = n * 2
			if n > 9 {
				n = n%10 + n/10
			}
		}

		num += n
	}
	
	// case 1: single 0 is invalid
	// case 2: number not divisible by 10 not valid
	// this won't be caught in the length check earlier if the string has a
	// space and a 0 like " 0" hence the digits count kept earlier will be helpful
	if (num == 0 && digits == 1) || (num%10 != 0) {
		return false
	}

	return true
}
