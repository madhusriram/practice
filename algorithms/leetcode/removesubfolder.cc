#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

/*
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
"/a" "/a/b" "/c/d" "/c/d/e" "/c/f"
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
*/

using namespace std;

bool isValidDir(string dir) {
	if (dir.size() == 1 && (dir == " " || dir == "/"))
		return false;

	return true;
}

// tells if sub is a subdirectory of parent
bool isSubDir(string parent, string sub) {
	size_t found = sub.find(parent);
	int len = parent.size();

	if ((found == 0 && sub.size() == len) || (found == 0 && sub.at(len) == '/'))
		return true;

	return false;
}

vector<string> removeSubDir(vector<string> &folders) {
	// sort lexicographically
	sort(folders.begin(), folders.end());
	vector<string> removedList;

	int len = folders.size();

	// iterate through folders using .at()
	for (int i = 0; i < len; i++) {
		string parent = folders.at(i);
		if (! isValidDir(parent))
			continue;
		removedList.push_back(parent);

		while (i + 1 < len) {
			string sub = folders.at(++i);
			if (! isValidDir(sub))
				continue;
			bool isSub = isSubDir(parent, sub);

			// if not a subdirectory then this might be a parent of someone else
			// later, exit out of this loop
			if (! isSub) {
				i--;		// to accomodate for the i++ in the outer loop
				break;
			}
		}
	}
	return removedList;
}

int main() {
	vector<string> folders;

	cout << "Enter directories: ";
	string str;

	getline(cin, str);
	istringstream sstr(str);
	string tmp;

	while (sstr >> tmp)
		folders.push_back(tmp);


	vector<string> removed = removeSubDir(folders);

	cout << "Curated directory list: " << endl;
	for (auto i : removed) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
