package main

import "fmt"

func main() {
	a := &Node{1, nil, nil, nil}
	b := &Node{2, nil, nil, nil}
	c := &Node{3, nil, nil, nil}
	d := &Node{4, nil, nil, nil}
	a.Next = b
	b.Prev = a
	b.Child = c
	b.Next = d
	d. Prev = b
	r := flatten(a)
	for r != nil {
		fmt.Println(r.Val)
	}

}
