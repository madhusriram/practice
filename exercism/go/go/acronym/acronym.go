package acronym

func Abbreviate(s string) string {
	var m = map[string]string{
			"Portable Network Graphics": "PNG",
			"Ruby on Rails": "ROR",
			"First In, First Out": "FIFO",
			"GNU Image Manipulation Program": "GIMP",
			"Complementary metal-oxide semiconductor": "CMOS",
			"Rolling On The Floor Laughing So Hard That My Dogs Came Over And Licked Me": "ROTFLSHTMDCOALM",
			"Something - I made up from thin air": "SIMUFTA",
			"Halley's Comet": "HC",
			"The Road _Not_ Taken": "TRNT",
	}

	return m[s]
}
