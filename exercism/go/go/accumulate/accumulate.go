// Package accumulate modifies user input based on the callback
package accumulate

// Accumulate executes a callback function on each input string
func Accumulate(input []string, cb func(string) string) []string {
	var res []string

	for _, s := range input {
		res = append(res, cb(s))
	}

	return res
}
