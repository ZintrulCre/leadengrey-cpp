package main

type Node struct {
    Val int
    Next *Node
    Prev *Node
    Child *Node
}

type ListNode struct {
    Val int
    Next *ListNode
}