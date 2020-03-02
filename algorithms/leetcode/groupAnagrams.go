package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

type sortRunes []rune

func (s sortRunes) Len() int {
	return len(s)
}

func (s sortRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func groupAnagrams(strs []string) [][]string {
	var res [][]string
	sliceLen := 0

	// link between string and its position in the result map
	var m map[string]int
	m = make(map[string]int)

	for _, v := range strs {
		r := []rune(v)
		sort.Sort(sortRunes(r))
		s := string(r)

		// if sorted strings exists in the map
		// find its index and append to it
		if i, ok := m[s]; !ok {
			res = append(res, []string{v})
			m[s] = sliceLen // store sorted string as key and the index in the map as value
			sliceLen++
		} else {
			res[i] = append(res[i], v)
		}
	}
	return res
}

// Uses hash map to store the index of the map where the results are stored
// Sorts each string in the input slice and uses the sorted string as the key in ma[
// and value being the index at which the actual string is stored in the result

// Another way is to not to sort but just read in the string maintaining a bit mask
// and using that as a key to the map. That would result in constant time instead
// of the nlogn operation involved in sorting
func main() {
	r := bufio.NewReader(os.Stdin)
	var s string
	var err error

	fmt.Printf("Enter text: ")
	if s, err = r.ReadString('\n'); err != nil {
		fmt.Printf("Error reading from stdin, err=%v", err)
		os.Exit(1)
	}

	// trim the new line character
	s = strings.TrimRight(s, "\n")

	res := groupAnagrams(strings.Split(s, " "))
	fmt.Println(res)
}
