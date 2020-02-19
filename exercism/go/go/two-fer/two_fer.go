// Package twofer creates a sentence based on name
package twofer

// ShareWith creates a sentence and returns a string
func ShareWith(name string) string {
	if name == "" {
		name = "you"
	}

	return "One for " + name + ", one for me."
}
