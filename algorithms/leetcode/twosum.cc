#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;


int main() {
	vector<int> v;
	int targetSum;

	cout << "Enter the array: ";
	string str;
	getline(cin, str);
	istringstream sstr(str);
	int n;
	while (sstr >> n)
		v.push_back(n);

	cout << "Enter the target sum: ";
	cin >> targetSum;

	map<int, int> m;
	
	int i = 0;

	// iterate the vector
	for (auto it = v.begin(); it != v.end(); it++, i++) {
		// not in map
		int diff = targetSum - *it;
		if (m.find(*it) == m.end()) {
			m[diff] = i;
		} else {
			cout << "[ " << m[diff] << " " << i << " ]" << endl;
			break;
		}
	}
	return 0;
}
