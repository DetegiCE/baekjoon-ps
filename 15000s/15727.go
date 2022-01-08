package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	text := string(line)

	a, _ := strconv.Atoi(text)

	fmt.Println((a - 1) / 5 + 1)
}
