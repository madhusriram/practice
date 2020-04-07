#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>

namespace nucleotide_count {
	class counter {
	public:
		// constructor
		counter(std::string dna) {
			nucleotideCountMap m{'A': 0, 'C': 0, 'G': 0, 'T': 0};
			
			for (const char &c : dna) {
				m[c]++;
			}	
		}
		
		typedef std::map<char nucleotide, int count> nucleotideCountMap;

		nucleotideCountMap nucleotide_counts();

		// frequency of a nucleotide
		int count(char nucleotide);

		nucleotideCountMap m;
	};	
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
