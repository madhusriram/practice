#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <deque>


// https://leetcode.com/problems/backspace-string-compare/
// Given 2 strings S and T, return if they are equal, # means backspace characters
// S = ab#c T = ad#c
// output: True
// Both S and T become ac

#define STRING_LEN 1000

using namespace std;

// method 2 uses 2 pointer method
bool checkBackspacedStrings2(const char *str1, int len1, const char *str2, int len2) {
    int i = len1 - 1;
    int j = len2 - 1;
    char c1, c2;
    int skip1 = 0;
    int skip2 = 0;

    while (i >= 0 || j >= 0) {
        // reset char's
        c1 = ' ';
        c2 = ' ';

        // scan backward str1 until a char is hit
        for ( ; i >= 0; i--) {
            if (str1[i] == '#') {
                skip1++;
                continue;
            }
            if (skip1 > 0) {
                skip1--;
                continue;
            }
            c1 = str1[i];
             i--;
             break;
        }
        cout << "Character 1: " << i << " " << c1 << " " << endl;

        // scan backward str2 until a char is hit
        for ( ; j >= 0; j--) {
            if (str2[j] == '#') {
                skip2++;
                continue;
            }
            if (skip2 > 0) {
                skip2--;
                continue;
            }
            c2 = str2[j];
            j--;
            break;
        }

        // compare char's got out of the string
        if (c1 != c2)
            return false;
     }

     return true;
}

bool checkBackspacedStrings(const char *str1, int len1, const char *str2, int len2) {
    // both zero length, no-brainer
    if (len1 == 0 && len2 == 0)
        return true;

    deque<char >d1;
    deque<char >d2;

    for (int i = 0; i < len1; i++) {
        if (str1[i] != '#')
            d1.push_back(str1[i]);
        else if (! d1.empty())
            d1.pop_back();
    }

    for (int i = 0; i < len2; i++) {
        if (str2[i] != '#')
            d2.push_back(str2[i]);
        else if (! d2.empty())
            d2.pop_back();
    }
    
    // iterate both deque's
    deque<char>::iterator it1 = d1.begin();
    deque<char>::iterator it2 = d2.begin();


    for (; it1 != d1.end(), it2 != d2.end(); it1++, it2++) {
        if (*it1 != *it2)
            return false;        
    }

    if (it1 != d1.end() || it2 != d2.end())
        return false;
    
    return true;
}

// method -1 involves using additional queue which would be O(N) time and O(N) space
// method -2 involves using two pointer method (PENDING)
int main() {
	string str1, str2;
	const char *s1;
	const char *s2;
	
    printf("Enter string 1: ");
	getline(cin, str1);
    s1 = str1.c_str();
	int str1len = strlen(s1);

    printf("Enter string 2: ");
	getline(cin, str2);
	s2 = str2.c_str();
	int str2len = strlen(s2);

    printf("String 1: %s, string 2: %s\n", s1, s2); 

    // method1
    //bool res = checkBackspacedStrings(s1, str1len, s2, str2len);

    // method2
    bool res = checkBackspacedStrings2(s1, str1len, s2, str2len);

   	printf("String1: %s and string2: %s are ", s1, s2);
    if (res)
        printf("equal\n");
    else
        printf("not equal\n");
    
    return 0;
}
