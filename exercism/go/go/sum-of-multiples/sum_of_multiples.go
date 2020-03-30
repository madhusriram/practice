// Package summultiples returns the sum of multiples
package summultiples

// SumMultiples returns the sum of all multiples of the divisors until the limit
// is hit
func SumMultiples(limit int, divisors ...int) int {
	if len(divisors) == 0 {
		return 0
	}

	var sum int

	for i := 1; i < limit; i++ {
		for _, n := range divisors {
			if  n != 0 && i % n == 0 {
				sum += i
				break
			}
		}
	}

	return sum
}
