package main

import (
	"fmt"
	"os"
)

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func main() {
	var n int
	fmt.Fscanln(os.Stdin, &n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscanln(os.Stdin, &a, &b)
		if (a+b)%3 == 0 && min(a, b) >= (a+b)/3 {
			fmt.Println("YES")
		} else {
			fmt.Println(("NO"))
		}
	}
}
