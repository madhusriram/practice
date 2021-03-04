package clock

import "fmt"

const (
	hoursPerDay    = 24 // Hours in a day
	minutesPerHour = 60 // Minutes in an hour
)

// Clock stores fixed minute and hour
type Clock struct {
	h int // hours as int
	m int // minutes as int
}

// fixTime fixes an incorrect clock
func (c Clock) fixTime() Clock {
	hourFromMinutes := c.m / minutesPerHour
	c.m = c.m % minutesPerHour
	c.h = (c.h + hourFromMinutes) % hoursPerDay

	// adjust minutes and hours if minutes was negative
	if c.m < 0 {
		// adjust minutes, this is effectively reduction in an hour as well
		// adjust hour by reducing by one
		c.m += minutesPerHour
		c.h = c.h - 1
	}

	// finally, if hour was negative adjust that too
	if c.h < 0 {
		c.h += hoursPerDay
	}

	return c
}

// String returns a string representation of Clock
func (c Clock) String() string {
	return fmt.Sprintf("%02d:%02d", c.h, c.m)
}

// Add adds 'a' minutes to the clock and returns a new clock
func (c Clock) Add(a int) Clock {
	c.m += a
	return New(c.h, c.m)
}

// Subtract reduces 's' minutes from the clock and returns a new clock
func (c Clock) Subtract(s int) Clock {
	c.m -= s
	return New(c.h, c.m)
}

// New creates a time string from 2 integers
func New(h int, m int) Clock {
	var c Clock
	c.h = h
	c.m = m

	return c.fixTime()
}
