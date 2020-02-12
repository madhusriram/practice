#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int mystrstr(const char *needle, const char *haystack) {
	int needleLen = strlen(needle);
	int haystackLen = strlen(haystack);
	int pos = -1;
	bool found = false;

	if (needleLen > haystackLen)
		return pos;

	if (needleLen == 0)
		return 0;

	// non-optmized
	int i = 0;
	int j = 0;
	for (i = 0; i < (haystackLen - needleLen + 1); i++) {
		pos = i;
		for (j = 0; j < needleLen; j++) {
			printf("i: %d(%c), j: %d(%c)\n", j, needle[j], i+j, haystack[i+j]);
			if (needle[j] != haystack[i + j])
				break;
			// exit as soon as we find!
			if (j + 1== needleLen && needle[j] == haystack[i + j])
				found = true;
		}
		if (found)
			break;
	}
	return pos;
}

int main() {
	string needle;
	string haystack;

	printf("Needle\n");
	getline(cin, needle);

	printf("Haystack\n");
	getline(cin, haystack);

	int pos = mystrstr(needle.c_str(), haystack.c_str());

	if (pos == -1) {
		printf("Needle(%s) not in haystack(%s)\n", needle.c_str(), haystack.c_str());
	} else {
		printf("Needle: %s is in haystack at position: %d\n", needle.c_str(), pos);
	}

	return 0;
}
