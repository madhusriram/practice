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

bool checkBackspacedStrings(char *str1, int len1, char *str2, int len2) {
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
    char str1[STRING_LEN];
    char str2[STRING_LEN];

    printf("Enter string 1: ");
    fgets(str1, STRING_LEN, stdin);
    printf("Enter string 2: ");
    fgets(str2, STRING_LEN, stdin);

    // remove new-line character at the end
    // fgets adds a '\n' at the end
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    str1[str1len -1] = '\0';
    str2[str2len - 1] = '\0';

    printf("String 1: %s, string 2: %s\n", str1, str2);

    // method1
    bool res = checkBackspacedStrings(str1, str1len, str2, str2len);

    // method2
    
    printf("String1: %s and string2: %s are ", str1, str2);
    
    if (res)
        printf("equal\n");
    else
        printf("not equal\n");
    
    return 0;
}