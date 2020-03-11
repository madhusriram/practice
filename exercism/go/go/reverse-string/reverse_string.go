// Package reverse reverses a string
package reverse

// Reverse returns a new string, a reverse of the input
func Reverse(input string) string {
	if input == "" {
		return ""
	}

	res := make([]rune, len(input))
	i := 0
	// store input string in a slice of runes
	for _, r := range input {
		res[i] = r
		i++
	}
	res = res[0:i]

	// reverse rune now
	for j := 0; j < i/2; j++ {
		res[j], res[i-1-j] = res[i-1-j], res[j]
	}

	return string(res)
}
