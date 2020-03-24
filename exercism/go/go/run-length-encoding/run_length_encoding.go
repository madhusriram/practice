package encode

import "strconv"
import "fmt"

func RunLengthEncode(input string) string {
	// empty string
	if input == "" {
		return ""
	}

	var count int = 0
	var result string
	var prev rune

	for _, c := range input {
		if prev != c {
			if count > 1 {
				result += strconv.Itoa(count) // count
			}
			result += string(prev)
			count = 1
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

	return ""
}
