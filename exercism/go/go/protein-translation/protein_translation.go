// Package protein converts RNA sequences to their equivalent protein names
package protein

import (
	"errors"
)

// protein to codon match
var proteinMap = map[string]string{
	"AUG": "Methionine",
	"UUU": "Phenylalanine",
	"UUC": "Phenylalanine",
	"UUA": "Leucine",
	"UUG": "Leucine",
	"UCU": "Serine",
	"UCC": "Serine",
	"UCA": "Serine",
	"UCG": "Serine",
	"UAU": "Tyrosine",
	"UAC": "Tyrosine",
	"UGU": "Cysteine",
	"UGC": "Cysteine",
	"UGG": "Tryptophan",
	"UAA": "",
	"UAG": "",
	"UGA": "",
}

var ErrStop error = errors.New("Stop")
var ErrInvalidBase error = errors.New("Invalid Codon")

// FromCodon converts a sequence to its protein
func FromCodon(sequence string) (string, error) {
	if protein, ok := proteinMap[sequence]; ok {
		if protein == "" {
			return protein, ErrStop
		}
		return protein, nil
	}
	return "", ErrInvalidBase
}

// FromRNA converts a RNA sequence to a list of proteins
func FromRNA(sequence string) ([]string, error) {
	var proteinList []string

	r := []rune(sequence)
	count := 3

	for i := range r {
		if (i+1)%count == 0 {
			protein, err := FromCodon(string(r[i+1-count : i+1]))
			// stop at ErrStop
			if err == ErrStop {
				break
			}
			if err != nil {
				return proteinList, err
			}
			proteinList = append(proteinList, protein)
		}
	}
	return proteinList, nil
}
