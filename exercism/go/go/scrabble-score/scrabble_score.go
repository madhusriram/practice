// Package scrabble implements a scoring system
package scrabble

import (
	"strings"
	"unicode"
)

var m = map[string]int{
	"aeioulnrst": 1,
	"dg":         2,
	"bcmp":       3,
	"fhvwy":      4,
	"k":          5,
	"jx":         8,
	"qz":         10,
}

// Score calculates the score of a scrabble word
func Score(word string) int {
	r := []rune(word)
	var score int

	for _, v := range r {
		for k, s := range m {
			if strings.ContainsRune(k, unicode.ToLower(v)) {
				score += s
				break
			}
		}
	}
	return score
}
