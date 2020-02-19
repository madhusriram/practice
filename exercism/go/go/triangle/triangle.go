// Package triangle identifies type of a triangle
package triangle

import "math"

type Kind int

const (
	// Pick values for the following identifiers used by the test program.
	NaT Kind = iota // not a triangle
	Equ             // equilateral
	Iso             // isosceles
	Sca             // scalene
)

// KindFromSides returns type of a triangle based on its sides
func KindFromSides(a, b, c float64) Kind {

	// check if it's a triangle, first!
	// sum of the length of any 2 sides must be greater
	// than the length of the third side

	if a <= 0 || b <= 0 || c <= 0 {
		return NaT
	}
	if math.IsNaN(a) || math.IsNaN(b) || math.IsNaN(c) {
		return NaT
	}
	if math.IsInf(a, 1) || math.IsInf(b, 1) || math.IsInf(c, 1) {
		return NaT
	}
	if math.IsInf(a, -1) || math.IsInf(b, -1) || math.IsInf(c, -1) {
		return NaT
	}
	if a+b < c || a+c < b || b+c < a {
		return NaT
	}

	// Equilateral
	if a == b && b == c {
		return Equ
	}

	// Isosceles
	if a == b || a == c || b == c {
		return Iso
	}

	// Scalene
	return Sca

}
