// Package luhn validates a credit card
package luhn

import (
	"unicode"
	"strings"
)

// Valid returns true if a credit card number is valid
func Valid(cc string) bool {
	newCc := strings.ReplaceAll(cc, " ","")
	lengthCc := len(newCc)
	
	// single digit strings not valid
	if lengthCc == 1 {
		return false
	}

	// accrue sum
	var num int = 0
	// alternates character reads from the cardi
	var double bool = false 
	if lengthCc%2 == 0 {
		double = !double
	}

	// start reading card from the left to right
	for _, d := range newCc {
		if !unicode.IsNumber(d) {
			return false
		}

		n := int(d - '0')

		// odd positions go through the doubling and subtracting by 9 logic
		if double {
			n = n * 2
			if n > 9 {
				n = n%10 + n/10
			}
		}

		double = !double
		num += n
	}

	// number not evenly divisible by 10 is not a valid card number
	if (num%10 != 0) {
		return false
	}

	return true
}
