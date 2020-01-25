#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

// https://leetcode.com/problems/remove-element/

int removeElement(std::vector<int>& v, int num) {
	v.erase(std::remove(v.begin(), v.end(), num), v.end());

	return v.size();

}

int main() {
	std::vector<int> v;
	int numToBeRemoved;

	std::cout << "Enter the array: ";
	std::string str;
	std::getline(std::cin, str);
	std::istringstream sstr(str);
	int n;
	while (sstr >> n)
		v.push_back(n);
	
	std::cout << "Enter the number to remove: ";
	std::cin >> numToBeRemoved;

	int newLen = removeElement(v, numToBeRemoved);

	for ( auto i : v ) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "New array length : " << newLen << std::endl;
}
