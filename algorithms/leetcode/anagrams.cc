#include <iostream>
#include <string>

// https://web.stanford.edu/class/cs9/sample_probs/Anagrams.pdf

using namespace std;

int main() {
	string str1;
	string str2;
	const char *s1;
	const char *s2;

	// string 1
	printf("String 1: \n");
	getline(cin, str1);
	int str1_len = str1.length();
	s1 = str1.c_str();

	// string 2
	printf("String 2: \n");
	getline(cin, str2);
	int str2_len = str2.length();
	s2 = str2.c_str();

	int freq[26] = {0};

	for (int i = 0; i < str1_len; i++) {
		freq[s1[i] - 'a'] += 1;
	}

	for (int i = 0; i < str2_len; i++) {
		if (freq[s2[i] - 'a'] == 0) {
			cout << "Not an anagram!" << endl;
			return -1;
		}
		freq[s2[i] - 'a'] -= 1;
			
	}

	cout << "Anagrams!" << endl;
	return 0;
}
