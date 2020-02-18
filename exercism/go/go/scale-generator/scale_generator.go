// Not interested in solving this!
package scale

import "strings"

// Scale accepts a tonic and a string representation of a sequence of intervals
// and generates a chromatic or diatonic scale.
func Scale(tonic string, interval string) []string {
	var scale []string

	switch tonic {
	case "C", "G", "D", "A", "E", "B", "F#", "a", "e", "b", "f#", "c#", "d#":
		scale = []string{"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"}
	default:
		scale = []string{"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"}
	}

	for i, note := range scale {
		// Start the scale on the input tonic
		if strings.ToLower(tonic) == strings.ToLower(note) {
			scale = append(scale[i:], scale[:i]...)
			break
		}
	}

	for i, step := range interval {
		// Close the gaps between each step of the interval
		switch step {
		case 'A':
			copy(scale[i+1:], scale[i+3:])
			scale = scale[:len(scale)-2]
		case 'M':
			copy(scale[i+1:], scale[i+2:])
			scale = scale[:len(scale)-1]
		}
	}
	return scale
}
