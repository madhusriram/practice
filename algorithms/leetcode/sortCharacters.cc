#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool sortInRev(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.first > b.first);	
}

string sortCharacter(string str) {
	vector<pair<int, int>> v;
	int freq[128] = {0};

	// get the mapping of frequencies to letters
	for ( auto c : str ) {
		++freq[c];
	}

	// iterate over string
	for (int i = 0; i < 128; i++) {
		if (freq[i] != 0)
			v.push_back(make_pair(freq[i], i));
	}

	// sort vector, vectors by default will sort based on the first key
	// of the pair
	sort(v.begin(), v.end(), sortInRev);

	string res;
	int i = 0;
	// read from the end, for descending order
	while (i < v.size()) {
		res += v[i].second;
		--v[i].first;

		// if done with this character advance the vector
		if (v[i].first == 0)
			i++;
		
		cout << i << " " << v.size() << endl;
	}
	return res;
}

int main() {
	printf("Enter string: ");
	string str;
	getline(cin, str);

	
	string res = sortCharacter(str);

	cout << "Result string: " << res << endl;

	return 0;
}
