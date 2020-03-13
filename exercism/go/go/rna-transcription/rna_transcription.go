package strand

//G -> C
// C -> G
// T -> A
// A -> U

// ToRNA converts DNA sequence to RNA 
func ToRNA(dna string) string {
	dnaToRnaMap := make(map[string]string)

	dnaToRnaMap = map[string]string{
		"G": "C",
		"C": "G",
		"T": "A",
		"A": "U",
	}
	
	if dna == "" {
		return ""
	}

	var rna string

	for _, c := range dna {
		rna += dnaToRnaMap[string(c)]
	}
	return rna
}
