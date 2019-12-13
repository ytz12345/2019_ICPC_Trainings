package main

import (
	"fmt"
	"os"
)

func sqr(x int) int {
	return x * x
}

func main() {
	var n int
	fmt.Fscanln(os.Stdin, &n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscanln(os.Stdin, &a, &b)
		if a >= b {
			fmt.Println(b)
		} else {
			ans := 0
			for j := 0; j < a; j++ {
				if j < b%a {
					ans += sqr(b/a + 1)
				} else {
					ans += sqr(b / a)
				}
			}
			fmt.Println(ans)
		}
	}
}
