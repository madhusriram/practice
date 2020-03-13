package strain

type Ints []int
type Lists [][]int
type Strings []string

func (ints Ints) Keep(fn func (int) bool) Ints {
	if ints == nil {
		return nil
	}

	var res Ints

	for _, v := range ints {
		ok := fn(v)
		if ok {
			res = append(res, v)
		}
	}

	return res
}

func (ints Ints) Discard(fn func (int) bool) Ints {
	if ints == nil {
		return nil
	}

	var res Ints

	for _, v := range ints {
		ok := fn(v)
		if ! ok {
			res = append(res, v)
		}
	}
	return res
}

func (strings Strings) Keep(fn func (string) bool) Strings {
	if strings == nil {
		return nil
	}

	var res Strings

	for _, v := range strings {
		ok := fn(v)
		if ok {
			res = append(res, v)
		}
	}

	return res
}

func (lists Lists) Keep(fn func ([]int) bool) Lists {
	if lists == nil {
		return nil
	}
	var res Lists

	for _, l := range lists {
		ok := fn(l)
		if ok {
			res = append(res, l)
		}
	}
	return res
}
