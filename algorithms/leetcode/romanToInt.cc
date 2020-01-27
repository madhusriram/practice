#include <iostream>
#include <map>

/*
https://leetcode.com/problems/roman-to-integer/
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Input: "IV"
Output: 4

Input: "IX"
Output: 9

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

using namespace std;

map<char, int> m = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

int main() {
	string str;
	const char *roman;
	int romanInt = 0;

	cout << "Enter the roman literal: ";
	getline(std::cin, str);
	
	roman = str.c_str();

	while (*roman != '\0') {
		if ((*roman == 'I' || *roman == 'X' || *roman == 'C') && *(roman + 1) != '\0') {
			if (*roman == 'C') {
				if (*(roman + 1) == 'D') {
					romanInt += 400;
					roman = roman + 2;
				} else if (*(roman + 1) == 'M') {
					romanInt += 900;
					roman = roman + 2;
				} else {
					romanInt += 100;
					roman++;
				}
			} else if (*roman == 'X') {
				if (*(roman + 1) == 'L') {
					romanInt += 40;
					roman = roman + 2;
				} else if (*(roman + 1) == 'C') {
					romanInt += 90;
					roman = roman + 2;
				} else {
					romanInt += 1;
					roman++;
				}
			} else if (*roman == 'I') {
				if (*(roman + 1) == 'V') {
					romanInt += 4;
					roman = roman + 2;
				} else if (*(roman + 1) == 'X') {
					romanInt += 9;
					roman = roman + 2;
				} else {
					romanInt += 1;
					roman++;
				}
			}
			continue;
		} else {
			switch (*roman) {
				case 'V':
					romanInt += m['V'];
					break;
				case 'L':
					romanInt += m['L'];
					break;
				case 'D':
					romanInt += m['D'];
					break;
				case 'M':
					romanInt += m['M'];
					break;
				case 'I':
					romanInt += m['I'];
					break;
				case 'C':
					romanInt += m['C'];
					break;
				case 'X':
					romanInt += m['X'];
					break;
				default:
					cout << "Invalid character: " << *roman << endl;
					exit(1);
			}
			roman++;
		}
	}

	cout << "Roman to Integer: " << romanInt << endl;
}
