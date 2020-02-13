#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> v = {0, 1, 0, 3, 12};

	v.erase(std::remove(v.begin(), v.end(), 0), v.end());

	for ( auto i : v ) {
		std::cout << i << std::endl; 
	}

	return 0;
}

