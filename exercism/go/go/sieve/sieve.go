// Package sieve calculates prime numbers until limit using Sieve of Erathosthenes algorithm
package sieve

// Sieve returns all primes between 2 to limit
func Sieve(limit int) []int {
	primes := make([]int, 0, limit/2)

	// no primes under 2
	if limit < 2 {
		return primes
	}

	// list contains numbers from 2 to limit
	numberList := make([]int, limit-1)

	// iterate through numberList and add to primes...
	// ...if that value at the index is 0
	// Space O(N)
	for i, v := range numberList {
		if v == 0 {
			primes = append(primes, i+2)
		}

		// number based from index
		number := i + 2

		// set all multiples of number to 1
		for x := number; x <= limit; x += number {
			numberList[x-2] = 1
		}
	}

	return primes
}
