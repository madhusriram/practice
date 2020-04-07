#include "nucleotide_count.h"

namespace nucleotide_count {
	nucleotideCountMap nucleotide_counts() {
		return m; 
	}

	int count(char nucleotide) {
		return m[nucleotide];
	}
}  // namespace nucleotide_count
