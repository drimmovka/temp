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

func New(size int) *LinkedList {
	// Initialize a new list. The number of elements size.

	if size <= 0 {
		fmt.Println("ERROR_New")
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

func (l *LinkedList) PrintList() {
	// List output
	display := ""
	current := l.Head

	for current.Next != nil {
		display += strconv.Itoa(current.Val) + " -> "
		current = current.Next
	}
	fmt.Println(display + strconv.Itoa(current.Val))
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
	i := 0
	for ; i != pos && current.Next != nil; i++ {
		current = current.Next
	}

	if i != pos {
		fmt.Println("ERROR_At")
		return Node{}
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

func (l *LinkedList) UpdateAt(pos int, val int) {
	// Make the value at the pos position equal to val.
	current := l.Head
	i := 0
	for ; i != pos && current.Next != nil; i++ {
		current = current.Next
	}

	if i != pos {
		fmt.Println("ERROR_UpdateAt")
		return
	}

	current.Val = val
}

func (l *LinkedList) Pop() {
	// Remove an element from the end.

	if l.Head.Next == nil {
		fmt.Println("ERROR_Pop: Unable to delete element, list size is already 1")
		return
	}

	current := l.Head
	for current.Next.Next != nil {
		current = current.Next
	}
	current.Next = nil
}

func (l *LinkedList) DeleteAt(pos int) {
	// Remove an item from the pos position.
	if l.Head.Next == nil {
		fmt.Println("ERROR_DeleteAt: Unable to delete element, list size is already 1")
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
		fmt.Println("ERROR_DeleteAt")
		return
	}

	current.Next = current.Next.Next
}

func NewFromSlise(s []int) *LinkedList {
	// Creating a linked list from a slice.

	if len(s) == 0 {
		fmt.Println("ERROR_NewFromSlise")
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
	/*
		list := New(-1)
		fmt.Println("Size:", list.Size())
		fmt.Println(list.At(10))
		list = New(10)
		for i := 0; i < list.Size(); i++ {
			list.UpdateAt(i, i*i)
		}
		list.PrintList()

		s := []int{}
		fmt.Printf("%T\n", s)
		fmt.Println(len(s))
	*/
	/*
		s := []int{-11, 22, 33, 44, -55, 66, -77}
		s := []int{-11}
		list := NewFromSlise(s)
		fmt.Println("size:", list.Size())
		for i := 0; i < list.Size(); i++ {
			fmt.Println("[", i, "]:", list.At(i))
		}
		fmt.Println("")
		list.PrintList()
	*/

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

}
