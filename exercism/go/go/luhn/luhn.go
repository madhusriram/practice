// Package luhn validates a credit card
package luhn

import (
	"unicode"
	"strings"
)

// Valid returns true if a credit card number is valid
func Valid(cc string) bool {
	cc = strings.ReplaceAll(cc, " ","")
	
	// single digit strings not valid
	if len(cc) == 1 {
		return false
	}

	// accrue sum
	var num int

	// alternates character reads from the cardi
	double := len(cc)%2 == 0

	// start reading card from the left to right
	for _, d := range cc {
		if !unicode.IsDigit(d) {
			return false
		}

		n := int(d - '0')

		// odd positions go through the doubling and subtracting by 9 logic
		if double {
			n *= 2
			if n > 9 {
				n -= 9
			}
		}

		double = !double
		num += n
	}

	// number not evenly divisible by 10 is not a valid card number
	return num%10 == 0
}
