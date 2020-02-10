#include <iostream>

using namespace std;

// https://leetcode.com/problems/long-pressed-name/

// saeed ssaaeed
bool isLongPressedName(const char *s1, int s1len, const char *s2, int s2len) {
    int i, j;
    char prev_char = ' ';

    for(i = 0, j = 0; i < s1len || j < s2len; i++, j++) {
        if (s1[i] == s2[j]) {
            prev_char = s2[j];        
        } else if (prev_char == s2[j]) {
            i--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string s1;
    string s2;

    printf("Enter string 1\n");
    getline(cin, s1);

    printf("Enter string 2\n");
    getline(cin, s2);
    
    bool res = isLongPressedName(s1.c_str(), s1.size(), s2.c_str(), s2.size());

    printf("%s is%s long pressed name of %s", s2.c_str(), (res) ? " a" : " not a", s1.c_str());
       
    return 0;
}