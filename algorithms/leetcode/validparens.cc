#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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


	return 0;
}
