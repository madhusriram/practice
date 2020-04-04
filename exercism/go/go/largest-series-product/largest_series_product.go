// Package lsproduct returns the max product of a sequence of numbers
package lsproduct

import (
	"fmt"
	"unicode"
)

// LargestSeriesProduct returns the product of the largest possible
// consecutive sequence of numbers
func LargestSeriesProduct(digits string, span int) (res int64, err error) {
	res = 0
	lenStr := len(digits)

	// span must be the smaller than the string length
	if lenStr < span {
		err = fmt.Errorf("Span(%d) cannot be greater than the length of the string(%d)", span, lenStr)
		return
	} else if span < 0 {
		err = fmt.Errorf("Span(%d) should be greater than 0")
		return
	} else if span == 0 {
		res = 1
		return
	}

	// the logic would be to group span worth of
	// rune's and iterate them over and find the result
	for i := range digits {
		if i+span <= lenStr {
			substr := digits[i:i+span]
			var mult int64 = 1

			for pos, v := range substr {
				if unicode.IsLetter(v) {
					res = -1
					err = fmt.Errorf("No letters allowed in digits, letter(%s) found at pos:%d", v, pos)
					return
				}
				mult *= int64(v - '0')
			}

			// update the latest and greatest
			if mult > res {
				res = mult
			}
		}
	}
	return
}
