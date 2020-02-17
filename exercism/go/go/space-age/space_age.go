package space

type Planet string

func Age(secs float64, planet Planet) float64 {
	var actual float64

	var earthSecs float64 = 31557600

	switch planet {
	case "Earth":
		return secs / earthSecs
	case "Mercury":
		return secs / (earthSecs * 0.2408467)
	case "Venus":
		return secs / (earthSecs * 0.61519726)
	case "Mars":
		return secs / (earthSecs * 1.8808158)
	case "Jupiter":
		return secs / (earthSecs * 11.862615)
	case "Saturn":
		return secs / (earthSecs * 29.447498)
	case "Uranus":
		return secs / (earthSecs * 84.016846)
	case "Neptune":
		return secs / (earthSecs * 164.79132)
	}

	return actual
}
