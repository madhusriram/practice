// Package isbn validates book identification numbers 
package isbn

import (
	"unicode"
)

// IsValidISBN verifies if a input string is a valid ISBN code
func IsValidISBN(input string) bool {
		sum := 0
		isbnDigitCount := 10 

		for _, d := range input {
			if d == 'X' && isbnDigitCount == 1 { // 'X' should only be in the units place
				sum += 10 * isbnDigitCount
				isbnDigitCount--
			} else if unicode.IsDigit(d) {
				sum += int(d - '0') * isbnDigitCount
				isbnDigitCount--
			} else if d != '-' {
				return false
			}
		}

	// incorrect digit count or the sum doesn't add up 
	if sum % 11 != 0 || isbnDigitCount != 0 {
		return false
	}
	return true
}
