//Package proverb provides tools to create fancy proverbs
package proverb

import "fmt"

//Proverb accepts list of words and returns a proverb built using those words.
func Proverb(rhyme []string) []string {
	length := len(rhyme)
	if length == 0 {
		return []string{}
	}

	var res []string
	p1 := "And all for the want of a %s."
	p2 := "For want of a %s the %s was lost."

	lastMsg := fmt.Sprintf(p1, rhyme[0])
	
	for i := 0; i < length - 1; i++ {
		s := fmt.Sprintf(p2, rhyme[i], rhyme[i+1])
		res = append(res, s)
	}
	
	res = append(res, lastMsg)
	
	return res
}
