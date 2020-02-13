#include <string>
#include <iostream>

// https://leetcode.com/problems/reverse-vowels-of-a-string/

using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

char *reverseVowels(char *arr) {
	// search until you hit the first vowel
	// have 2 pointers move them along until first vowel is hit
	// then only move the second pointer till it hits another vowel
	char *tmp = arr;
	char *f = tmp;
	char *s = tmp;

	// run until the second pointer hits the end
	while (*s != '\0') {
		if (isVowel(*s)) {
			s++;
			while (*s != '\0') {
				// swap f and s
				if (isVowel(*s)) {
					char t = *s;
					*s = *f;
					*f = t;

					// move f to s
					f = s;
				}
				s++;
			}
			break;
		}
		// move both along since we haven't found a single vowel, yet!
		f++;
		s++;
	}

	return arr;
}

int main() {
	string in;
	printf("Enter vowelified string!\n");
	getline(cin, in);

	char *out = reverseVowels((char *)in.c_str());

	cout << out << endl;
	
	return 0;
}
