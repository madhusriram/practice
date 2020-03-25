package encode

import "strconv"
import "fmt"
import "unicode"
import "unicode/utf8"

func RunLengthEncode(input string) string {
	// empty string
	if input == "" {
		return ""
	}

	var count int = 0
	var result string
	prev, _ := utf8.DecodeRuneInString(input)

	for _, c := range input {
		// change of character
		if prev != c {
			if count > 1 {
				result += strconv.Itoa(count) // count
			}
			result += string(prev)
			count = 0
		}
		count += 1
		prev = c
	}

	if count > 1 {
		result += strconv.Itoa(count)
	}
	result += string(prev)

	fmt.Printf("Input: %s, result: %s\n", input, result)
	return result
}

func RunLengthDecode(input string) string {
	// empty string
	if input == "" {
		return ""
	}

	var n int = 0
	var decodedString string

	for _, c := range input {
		// save number
		// there will be chances of having numbers > 10
		// multiply by 10 for every subsequently read number
		if unicode.IsNumber(c) {
			n = n * 10 + int(c - '0')
			continue
		}

		// special case - for no number just 1 letter gets printed
		if n == 0 {
			decodedString += string(c)
			continue
		}

		for i := 0; i < n; i++ {
			decodedString += string(c)
		}

		n = 0
	}

	return decodedString 
}
