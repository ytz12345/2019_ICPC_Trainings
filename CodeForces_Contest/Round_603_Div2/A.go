package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	var n int
	s := []int{0, 0, 0}
	fmt.Fscanln(os.Stdin, &n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(os.Stdin, &s[0], &s[1], &s[2])
		sort.Ints(s)
		if s[2] >= s[0]+s[1] {
			fmt.Println(s[0] + s[1])
		} else {
			fmt.Println((s[0] + s[1] + s[2]) / 2)
		}
	}
}
