#include <iostream>

using namespace std;

// https://leetcode.com/problems/max-consecutive-ones/

int main() {
	const int arr[] = {1,1,0,1,1,1};
	int len = sizeof(arr)/sizeof(arr[0]);

	int largest = 0;
	int old_largest = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i] && 1) {
			largest++;
		} else {
			if (largest > old_largest)
				old_largest = largest;
			largest = 0;		
		}
	}

	printf("Largest consecutive ones: %d\n", largest > old_largest ? largest : old_largest);
}
