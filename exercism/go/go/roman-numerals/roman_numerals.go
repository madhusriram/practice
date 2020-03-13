package romannumerals

import (
	"errors"
)

func ToRomanNumeral(input int) (string, error) {
	if input <= 0 || input > 3000 {
		return "", errors.New("Invalid")
	}

	i := []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
	x := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
	c := []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
	m := []string{"", "M", "MM", "MMM"}

	thousandth := m[input/1000]
	hundredth := c[(input%1000)/100]
	tenth := x[(input%100)/10]
	oneth := i[input%10]

	res := thousandth + hundredth + tenth + oneth

	return res, nil
}
