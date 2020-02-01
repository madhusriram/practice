#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

/*
https://leetcode.com/problems/valid-parentheses/ 
*/

void printResult(bool success) {
	if (! success)  
		std::cout << "false" << std::endl;
	else
		std::cout << "true" << std::endl;

	exit(0);
}

int main() {
	std::vector<char> v;

	std::cout << "Enter the paranthesis string: ";
	std::string str;
	std::getline(std::cin, str);
	std::istringstream sstr(str);	
	
	char c;
	std::stack<char> stack;

	// ({}) , (({}
	while (sstr >> c) {
		if (c == '}' || c == ')' || c == ']') {
			if (stack.empty())
				printResult(false);
			char top = stack.top();
			if (top == '{' && c == '}') {
				stack.pop();
				continue;
			} else if (top == '(' && c == ')') {
				stack.pop();
				continue;
			} else if (top == '[' && c == ']') {
				stack.pop();
				continue;
			} else {
				printResult(false);
			}
		}
		stack.push(c);
	}

	if (stack.empty())
		printResult(true);
	else
		printResult(false);
	return 0;
}
