package main

import (
	"fmt"
	"strconv"
)

type Node struct {
	Val  int
	Next *Node
}

type LinkedList struct {
	Head *Node
}

// Initialize a new list. The number of elements size.
func New(size int) *LinkedList {

	if size <= 0 {
		fmt.Println("ERROR (in New): list size is set incorrectly")
		return &LinkedList{Head: &Node{}}
	}

	Head := Node{}
	current := &Head
	for i := 1; i < size; i++ {
		current.Next = &Node{}
		current = current.Next
	}
	return &LinkedList{Head: &Head}
}

// List output
func (l *LinkedList) PrintList() {
	display := ""
	current := l.Head

	for current.Next != nil {
		display += strconv.Itoa(current.Val) + " -> "
		current = current.Next
	}
	fmt.Println(display + strconv.Itoa(current.Val))
}

// Return the length of the list
func (l *LinkedList) Size() int {
	size := 1
	current := l.Head
	for current.Next != nil {
		size++
		current = current.Next
	}
	return size
}

// Getting an item from the pos position.
func (l *LinkedList) At(pos int) Node {
	current := l.Head
	i := 0
	for ; i != pos && current.Next != nil; i++ {
		current = current.Next
	}

	if i != pos {
		fmt.Println("ERROR (in At): list index out of range")
		return Node{}
	}

	return *current
}

// Add an item to the end of the list.
func (l *LinkedList) Add(val int) {
	current := l.Head
	for current.Next != nil {
		current = current.Next
	}
	current.Next = &Node{Val: val, Next: nil}
}

// Make the value at the pos position equal to val.
func (l *LinkedList) UpdateAt(pos int, val int) {
	current := l.Head
	i := 0
	for ; i != pos && current.Next != nil; i++ {
		current = current.Next
	}

	if i != pos {
		fmt.Println("ERROR (in UpdateAt): list index out of range")
		return
	}

	current.Val = val
}

// Remove an element from the end.
func (l *LinkedList) Pop() {

	if l.Head.Next == nil {
		fmt.Println("ERROR (in Pop): Unable to delete element, list size is already 1")
		return
	}

	current := l.Head
	for current.Next.Next != nil {
		current = current.Next
	}
	current.Next = nil
}

// Remove an item from the pos position.
func (l *LinkedList) DeleteAt(pos int) {

	if l.Head.Next == nil {
		fmt.Println("ERROR (in DeleteAt): Unable to delete element, list size is already 1")
		return
	}

	if pos == 0 {
		l.Head = l.Head.Next
		return
	}

	current := l.Head
	i := 0
	for ; i != pos-1 && current.Next != nil; i++ {
		current = current.Next
	}

	if i != pos-1 {
		fmt.Println("ERROR (in DeleteAt): list index out of range")
		return
	}

	current.Next = current.Next.Next
}

// Creating a linked list from a slice.
func NewFromSlise(s []int) *LinkedList {

	if len(s) == 0 {
		fmt.Println("ERROR (in NewFromSlise): Unable convert an empty slice to a list")
	}

	Head := Node{Val: s[0]}
	current := &Head
	for i := 0; i < len(s)-1; i++ {
		current.Next = &Node{Val: s[i+1]}
		current = current.Next
	}
	return &LinkedList{Head: &Head}
}

func main() {

	list := NewFromSlise([]int{-11, 22, 33, 44, -55, 66, -77})

	list.DeleteAt(0)

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

}
