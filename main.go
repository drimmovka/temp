package main

import "fmt"

type Node struct {
	Val  int
	Next *Node
}

type LinkedList struct {
	Head *Node
}

func New(q int) *LinkedList {
	// Инициализировать новый список. Количество элементов q.
	Head := Node{}
	current := &Head
	for i := 0; i < q; i++ {
		current.Next = &Node{}
		current = current.Next
	}
	return &LinkedList{Head: &Head}
}

func (l *LinkedList) Add(val int) {
	// Добавить элемент в конец списка.
	new_node := Node{Val: val, Next: nil}
	current := l.Head
	for i := 0; i < l.Size()-1; i++ {
		current = current.Next
	}
	current.Next = &new_node
}

func (l *LinkedList) Pop() {
	// Удалить элемент из конца.
	current := l.Head
	for i := 0; i < l.Size()-2; i++ {
		current = current.Next
	}
	current.Next = nil
}

func (l *LinkedList) At(pos int) Node {
	// Получение элемента из позиции pos.
	current := l.Head
	for i := 0; i < l.Size(); i++ {
		if i == pos {
			return *current
		}
		current = current.Next
	}
	return Node{}
}

func (l *LinkedList) Size() int {
	// Вернуть длину списка
	size := 1
	current := l.Head
	for {
		if current.Next == nil {
			break
		}
		size += 1
		current = current.Next
	}
	return size
}

func (l *LinkedList) DeleteFrom(pos int) {
	// Удалить элемент из позиции pos.
}

func (l *LinkedList) UpdateAt(pos int, val int) {
	// Значение на позиции pos сделать равным val.
	current := l.Head
	for i := 0; i < l.Size()-1; i++ {
		if i == pos {
			current.Val = val
			break
		}
		current = current.Next
	}
}

// func NewFromSlise(s []int) *LinkedList {
// 	// Создание связного списка из среза.
// }

func main() {
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
}
