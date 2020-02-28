// Package hamming calculates difference between 2 DNA strands
package hamming

import "errors"

// Distance returns the difference between two DNA strands
func Distance(a, b string) (int, error) {
	// Iterating the string directly compares byte by byte but each character
	// in a golang string can be multiple bytes. It is good to rather
	// compare runes by runes which would cover 4 byte comparison instead
	// of 1-byte
	c, d := []rune(a), []rune(b)

	if len(c) != len(d) {
		return 0, errors.New("inequal DNA strands")
	}

	hammingDistance := 0

	for i := range c {
		if c[i] != d[i] {
			hammingDistance++
		}
	}

	return hammingDistance, nil
}
