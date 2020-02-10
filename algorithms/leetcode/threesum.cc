#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

// https://leetcode.com/problems/3sum/
// find unique triplet when added gives you 0
// -7 -5 -1 1 3 4 7
// -5 -1 3 4 7

using namespace std;

int main() {
    vector<int> v{7,-1,-5,4,3};
    map<int, 
    sort(v.begin(), v.end());

    for (auto i : v) {
        cout << i << endl;
    }

    return 0;
}