package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func parseInts(s string) []int {
	fields := strings.Fields(s)
	ints := make([]int, len(fields))

	for i, f := range fields {
		ints[i], _ = strconv.Atoi(f)
	}
	return ints
}

// search returns -1 if the input wasn't found in the array
func search(input []int, target int) int {
	low := 0
	length := len(input)
	high := length - 1
	mid := length / 2
	pos := -1

	for low <= high {
		if input[mid] == target {
			return mid
		} else if input[mid] < target {
			low = mid + 1
			mid = (low + high) / 2
		} else {
			high = mid - 1
			mid = (low + high) / 2
		}
	}
	return pos
}

func main() {
	r := bufio.NewReader(os.Stdin)

	fmt.Printf("Enter sorted array: ")
	line, err := r.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	ints := parseInts(line)

	var target int
	fmt.Printf("Enter target number to find: ")
	fmt.Scanf("%d", &target)

	pos := search(ints, target)
	if pos == -1 {
		fmt.Printf("%d was not found in the input\n", target)
	} else {
		fmt.Printf("%d was found at %d position in the input\n", target, pos+1)
	}
}
