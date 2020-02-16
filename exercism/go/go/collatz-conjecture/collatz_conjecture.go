package collatzconjecture

import "fmt"

func CollatzConjecture(num int) (int, error) {
	var steps int

	if num <= 0 {
		return 0, fmt.Errorf("Number cannot be zero or negative")
	}
	for num != 1 {
		if num % 2 == 0 {
			 num = num / 2
		} else {
			 num = 3 * num + 1
		}
		steps++;
	}

	return steps, nil 
}
