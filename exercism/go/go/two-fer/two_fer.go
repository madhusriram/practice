// Two-fer creates a sentence
package twofer

// Creates a sentence
func ShareWith(name string) string {
	if name == "" {
		name = "you"
	}

	return "One for " + name + ", one for me."
}
