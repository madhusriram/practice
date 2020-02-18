// Package calculates the points earned in a darts game
package darts

import "math"

const (
	OUTER_RADIUS  = 10
	MIDDLE_RADIUS = 5
	INNER_RADIUS  = 1
)

// Score calculates score base on the cartesian co-ordinates
func Score(x, y float64) int {
	// inner circle radius of 1 - 10 points
	// middle circle radius of 5 - 5 points
	// outer circle radius of 10 - 1 point
	// outside - 0 points
	dist := math.Sqrt(x*x + y*y)

	if dist > OUTER_RADIUS {
		return 0
	} else if dist > MIDDLE_RADIUS {
		return 1
	} else if dist > INNER_RADIUS {
		return 5
	}

	return 10
}
