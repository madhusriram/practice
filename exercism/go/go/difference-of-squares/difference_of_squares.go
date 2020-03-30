// Package diffsquares finds the difference between the squares of sums
// and sum of squares
package diffsquares

// SquareOfSum returns the square of summed values
func SquareOfSum(n int) int {
	var res int

	res = (n * (n + 1)) / 2

	return res * res
}

// SumOfSquares returns the sum of squares
func SumOfSquares(n int) int {
	return (n * (n + 1) * (2*n + 1)) / 6
}

// Difference returns the difference of SquareOfSum and SumOfSquares
func Difference(n int) int {
	return SquareOfSum(n) - SumOfSquares(n)
}
