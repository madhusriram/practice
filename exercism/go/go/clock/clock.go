package clock

type Clock struct {
	h int 	// hours as int
	m int 	// minutes as int
}

// String returns a string representation of the clock
func (c Clock) String() string {

}

// Add adds 'a' minutes to the clock
// and returns a new clock
func (c Clock) Add(a int) Clock {

}

// Subtract reduces 's' minutes from the clock
// and returns a new clock
func (c Clock) Subtract(s int) Clock {

}

// New creates a time string from 2 integers
func New(h int, m int) Clock {
	return Clock{h: h, m: m}
}


