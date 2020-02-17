package acronym

import (
	"strings"
	"fmt"
)

func Abbreviate(s string) string {
	var res string
	for _, w := range strings.Split(s, " ") {
		w = strings.ToUpper(w)
		
		found := false

		for _, c := range w {
			if ! found && c >= 65  && c <= 90 {
				res += fmt.Sprintf("%c", c)
				found = true
			}
			if c == '-' {
				found = false
			}
		}
	}
	return res
}
