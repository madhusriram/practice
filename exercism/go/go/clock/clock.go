package clock

import "fmt"

// Clock stores fixed minute and hour
type Clock struct {
	m int // minutes as int
}

// String returns a string representation of Clock
func (c Clock) String() string {
		return fmt.Sprintf("%02d:%02d", c.m/60,c.m%60)
}

// Add adds 'a' minutes to the clock and returns a new clock
func (c Clock) Add(a int) Clock {
	return New(0, c.m+a)
}

// Subtract reduces 's' minutes from the clock and returns a new clock
func (c Clock) Subtract(s int) Clock {
	return New(0, c.m-s)
}

// New creates a time string from 2 integers
func New(hour int, minute int) Clock {
	m := minute + hour*60
	m %= 24 * 60
	if m < 0 {
		m += 24 * 60
	}
	return Clock{m}
}
