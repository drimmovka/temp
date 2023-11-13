package main

import "fmt"

func changeArray(arr *[5]int) {
	arr[0] = -1
}

func changeSlice(arr []int) {
	arr[0] = -1
}

type x struct {
	p1   int
	p2   int
	mas1 [5]int
	mas2 []int
}

func changeX(t *x) {
	t.p1 = 10
	t.p2 = 100
	t.mas1[0] = -111
	t.mas2 = append(t.mas2, 10)
}

func (t *x) methodChangeX() {
	t.p1 = 9
	t.p2 = 99
	t.mas1[0] = -222
	t.mas2 = append(t.mas2, 200)
}

func main() {
	a := [5]int{}             //array
	b := []int{1, 2, 3, 4, 5} //slice
	fmt.Println("a:", a)
	fmt.Println("b:", b)
	fmt.Printf("a: %T\nb: %T\n", a, b)

	changeArray(&a)
	changeSlice(b)

	fmt.Println("a:", a)
	fmt.Println("b:", b)

	aPtr := &a
	fmt.Println("&a/aPtr/aPtr[0]:", &a, aPtr, aPtr[0])
	fmt.Printf("T(&a): %T T(aPtr): %T\n", &a, aPtr)

	bPtr := &b
	fmt.Println("&b/bPtr/bPtr[0]:", &b, bPtr)
	fmt.Printf("T(&b): %T T(bPtr): %T\n", &b, bPtr)

	myX := x{}
	fmt.Println(myX, &myX)

	changeX(&myX)
	fmt.Println(myX, &myX)

	myX.methodChangeX()
	fmt.Println(myX, &myX)

	mega := []int{}
	for i := 0; i < 100; i++ {
		mega = append(mega, 100)
		fmt.Println(cap(mega))
	}
}
