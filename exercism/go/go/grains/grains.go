// Package grains calculates grains per square on a chess board
package grains

import (
	"fmt"
)

// Square calculates the grain count in a square
func Square(input int) (uint64, error) {
	if input <= 0 || input > 64 {
		return 0, fmt.Errorf("Invalid input, expect input betwnn 1 and 64")
	}

	return 1<<(input - 1), nil
}

// Total calculates the total number of grains in all squares
// Use sum of powers of 2 formula
func Total() uint64 {
	return 1<<64 - 1
}
