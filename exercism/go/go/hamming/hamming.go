// Package hamming calculates difference between 2 DNA strands
package hamming

import "errors"

// Distance returns the difference between two DNA strands
func Distance(a, b string) (int, error) {
	// if both strings are empty or
	// if the lengths do not match
	if a == "" && b == "" {
		return 0, nil
	}

	if len(a) != len(b) {
		return 0, errors.New("Inequal DNA strands")
	}

	diff := 0

	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			diff += 1
		}
	}

	return diff, nil
}
