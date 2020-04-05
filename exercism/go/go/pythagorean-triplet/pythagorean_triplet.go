package pythagorean

type Triplet [3]int

// Range returns a list of all Pythagorean triplets with sides in the
// range min to max inclusive
func Range(min, max int) []Triplet {
	res := make([]Triplet, 1)

	return res
}

func isPythagoreanTriplet(a, b, c int) bool {
	if a*a + b*b == c*c {
		return true
	}
	return false
}

// Sum returns a list of all pythagorean triplets where the sum a+b+c is equal to p
func Sum(sum int) []Triplet {
	res := make([]Triplet, 1)

	for a := 0; a < sum/3; a++ {
		for b := 0; b < a+1/2; b++ {
			if isPythagoreanTriplet(a,b,sum-b-a) {
				res = append(res, Triplet{a,b,sum-b-a})
			}
		}
	}
	return res
}
