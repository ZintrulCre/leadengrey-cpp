package main

func getKthFromEnd(head *ListNode, k int) *ListNode {
	a, b := head, head
	m := 0
	for a != nil {
		a = a.Next
		m++
		if m > k {
			b = b.Next
		}
	}
	return b
}