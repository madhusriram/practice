package anagram

import (
	"unicode"
	"strings"
)

func IsAnagram(subjectMap map[rune]int, candidate string) bool {
	candidateMap := make(map[rune]int)

	for _, c := range candidate {
		c := unicode.ToLower(c)
		candidateMap[c] += 1
	}

	// compare subject and candidate map
	for k, v := range subjectMap {
		if candidateMap[k] != v {
			return false
		}
	}
	return true
}

func Detect(subject string, candidates []string) []string {
	var res []string

	subjectMap := make(map[rune]int)
	for _, c := range subject {
		c = unicode.ToLower(c)
		subjectMap[c] += 1
	}

	for _, candidate := range candidates {
		// weed out inequal lengths
		if len(candidate) != len(subject) {
			continue
		}

		// words are not anagrams of themselves
		if strings.EqualFold(subject, candidate) {
			continue
		}

		if IsAnagram(subjectMap, candidate) {
			res = append(res, candidate)
		}
	}

	return res
}
