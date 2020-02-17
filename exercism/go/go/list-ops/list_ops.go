package listops

type IntList []int
type predFunc func(n int) bool
type binFunc func(x, y int) int
type unaryFunc func(x int) int

func (l IntList) Reverse() IntList {
	size := l.Length()

	for i := 0; i < size / 2; i++ {
		tmp := l[i]
		l[i] = l[size-i-1]
		l[size-i-1] = tmp
	}

	return l
}

func (l IntList) Concat(args []IntList) IntList {
	var newList IntList = l

	for _, list := range args {
		newList = newList.Append(list)
	}
	return newList
}

func (l IntList) Append(l2 IntList) IntList {
	newList := make([]int, l2.Length() + l.Length())

	i := 0

	// first list
	for _, v := range l {
		newList[i] = v
		i += 1
	}

	// append second list
	for _, v := range l2 {
		newList[i] = v
		i += 1
	}

	return newList
}

func (l IntList) Map(fn unaryFunc) IntList {
	for i, v := range l {
		l[i] = fn(v)
	}
	return l
}

func (l IntList) Length() int {
	size := 0
	for _, v := range l {
		_ = v
		size += 1
	}
	return size
}

func (l IntList) Filter(fn predFunc) []int {
	result := make(IntList, 0)
	
	for _, x := range l {
		if fn(x) {
			result = append(result, x)
		}
	}

	return result 
}

func (l IntList) Foldr(fn binFunc, initial int) int {
	var res int = initial
	size := l.Length()

	for i := size - 1; i >= 0; i-- {
		if res == 0 {
			res = fn(res, l[i])
		} else {
			res = fn(l[i], res)
		}
	}
	return res
}

func (l IntList) Foldl(fn binFunc, initial int) int {
	var res int = initial

	for _, v := range l {
		if res == 0 {
			res = fn(res, v)
		} else {
			res = fn(v, res)
		}
	}
	return res
}
