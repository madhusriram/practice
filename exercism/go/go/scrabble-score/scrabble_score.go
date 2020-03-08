// Package scrabble implements a scoring system
package scrabble

import "unicode"

// Score calculates the score of a scrabble word
func Score(word string) int {
	var score int

	for _, v := range word {
		v = unicode.ToLower(v)
		switch v {
		case 'a', 'e', 'i', 'o', 'u', 'l', 'n', 'r', 's', 't':
			score += 1
		case 'd', 'g':
			score += 2
		case 'b', 'c', 'm', 'p':
			score += 3
		case 'f', 'h', 'v', 'w', 'y':
			score += 4
		case 'k':
			score += 5
		case 'j', 'x':
			score += 8
		case 'q', 'z':
			score += 10

		}
	}

	return score
}
