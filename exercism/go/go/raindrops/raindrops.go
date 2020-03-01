// Package raindrops implements a conversion function returning a string based on an integer
package raindrops

import "strconv"

// Convert returns a string based on the integer input
func Convert(input int) string {
	response := ""

	if input%3 == 0 {
		response = "Pling"
	}
	if input%5 == 0 {
		response += "Plang"
	}
	if input%7 == 0 {
		response += "Plong"
	}

	if response == "" {
		return strconv.Itoa(input)
	}

	return response
}
