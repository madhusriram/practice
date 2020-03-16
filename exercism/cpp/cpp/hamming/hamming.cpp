#include "hamming.h"

namespace hamming {
	int compute(string s1, string s2) {
		int diff = 0;
		
		if (s1.length() != s2.length())
			throw std::domain_error("Invalid length!");

		for (unsigned int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				diff++;
		}
		return diff;
	}
}  // namespace hamming
