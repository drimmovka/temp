package main

import "fmt"

type Node struct {
	Val  int
	Next *Node
}

type LinkedList struct {
	Head *Node
}

func New(size int) *LinkedList {
	// Initialize a new list. The number of elements size.
	Head := Node{}
	current := &Head
	for i := 0; i < size-1; i++ {
		current.Next = &Node{}
		current = current.Next
	}
	return &LinkedList{Head: &Head}
}

func (l *LinkedList) Size() int {
	// Return the length of the list
	size := 1
	current := l.Head
	for current.Next != nil {
		size++
		current = current.Next
	}
	return size
}

func (l *LinkedList) At(pos int) Node {
	// Getting an item from the pos position.
	current := l.Head
	for i := 0; i != pos && current.Next != nil; i++ {
		current = current.Next
	}
	return *current
}

func (l *LinkedList) Add(val int) {
	// Add an item to the end of the list.
	current := l.Head
	for current.Next != nil {
		current = current.Next
	}
	current.Next = &Node{Val: val, Next: nil}
}

func (l *LinkedList) Pop() {
	// Remove an element from the end.
	current := l.Head
	if current.Next == nil {
		return
	}
	for current.Next.Next != nil {
		current = current.Next
	}
	current.Next = nil
}

func (l *LinkedList) UpdateAt(pos int, val int) {
	// Make the value at the pos position equal to val.
	current := l.Head
	for i := 0; i != pos && current.Next != nil; i++ {
		current = current.Next
	}
	current.Val = val
}

func (l *LinkedList) DeleteAt(pos int) {
	// Remove an item from the pos position.
	current := l.Head
	for i := 0; i != pos-1 && current.Next != nil; i++ {
		current = current.Next
	}
	current.Next = current.Next.Next
}

func NewFromSlise(s []int) *LinkedList {
	// Creating a linked list from a slice.
	Head := Node{Val: s[0]}
	current := &Head
	for i := 0; i < len(s)-1; i++ {
		current.Next = &Node{Val: s[i+1]}
		current = current.Next
	}
	return &LinkedList{Head: &Head}
}

func main() {

	s := []int{-11, 22, 33, 44, -55, 66, -77}
	list := NewFromSlise(s)
	fmt.Println("size:", list.Size())
	for i := 0; i < list.Size(); i++ {
		fmt.Println("[", i, "]:", list.At(i))
	}
	fmt.Println("")
	/*
		list := New(5)

		fmt.Println("size:", list.Size())
		for i := 0; i < list.Size(); i++ {
			fmt.Println("[", i, "]:", list.At(i))
		}
		fmt.Println("")

		list.Add(100)
		list.Add(200)
		list.Add(300)
		list.Add(400)
		list.UpdateAt(0, -50)
		list.UpdateAt(1, -5000)

		fmt.Println("size:", list.Size())
		for i := 0; i < list.Size(); i++ {
			fmt.Println("[", i, "]:", list.At(i))
		}
		fmt.Println("")

		list.Pop()
		list.Pop()

		fmt.Println("size:", list.Size())
		for i := 0; i < list.Size(); i++ {
			fmt.Println("[", i, "]:", list.At(i))
		}
		fmt.Println("")

		list.DeleteAt(5)
		fmt.Println("size:", list.Size())
		for i := 0; i < list.Size(); i++ {
			fmt.Println("[", i, "]:", list.At(i))
		}
		fmt.Println("")
	*/
}
