// Package etl transforms input from a list of letters assigned to a score
// to a letter assigned to a score
package etl

import "strings"

// Transform assigns a letter to a score
func Transform(input map[int][]string) map[string]int {

	res := make(map[string]int)

	for score, letters := range input {
		for _, letter := range letters {
			letter = strings.ToLower(letter)
			res[letter] = score
		}
	}
	return res
}
