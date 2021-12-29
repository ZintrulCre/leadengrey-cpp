package main

func flatten(root *Node) *Node {
	node := root
	for node != nil {
		if node.Child != nil {
			next := node.Next
			child := flatten(node.Child)
			node.Child = nil
			node.Next = child
			child.Prev = node
			temp := node
			for temp.Next != nil {
				temp = temp.Next
			}
			temp.Next = next
			if next != nil {
				next.Prev = temp
			}
			node = temp
		}
		node = node.Next
	}
	return root
}