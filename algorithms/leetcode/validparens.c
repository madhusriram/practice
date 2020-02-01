#include <stdio.h>
#include <string>
#include <vector>

/*
https://leetcode.com/problems/valid-parentheses/ 
*/

int main() {
	std::vector<char> v;
	
	std::cout << "Enter the paranthesis string: ";
	std::string str;
	std::getline(std::cin, str);
	std::istringstream sstr(str);	
	char c;
	while (sstr >> c)
		v.push_back(c);


	for ( auto i : v ) {
		std::cout << i << " ";
	}

	return 0;
}