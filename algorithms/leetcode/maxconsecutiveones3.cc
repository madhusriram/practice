#include <iostream>

// https://leetcode.com/problems/max-consecutive-ones-iii/
// Medium - sliding windown problem

// in this approach I reset the right window back to the left window if max 
// transitions have appeared. The optimization would be to leave the right
// window as is, moving the left window by 1 and adjusting the transition
// count appropriately.
int main() {
	const int arr[] = {1,1,1,0,0,0,1,1,1,1,0};
	int K = 1;
	// track 0->1 transitions
	int numConversions = 0;
	// consecutive 1's encountered
	int max_len = 0;
	// previous max
	int saved_max = 0;

	int arr_len = sizeof(arr)/sizeof(arr[0]);

	// left would move forward only when 0->1 transitions exceed K
	int left = 0;
	int right = 0;

	for (int right = 0; right < arr_len; right++) {
		if (arr[right] == 0) {
			numConversions++;
		}

		if (numConversions <= K) 
			max_len++;
		else		
			saved_max = (saved_max > max_len) ? saved_max : max_len;

		while (numConversions > K) {
			if (arr[left] == 0) {
				numConversions--;
			}
			left++;
			max_len--;
		}

	}

	printf("Consecutive one's: %d\n", (saved_max > max_len) ? saved_max : max_len); 

	return 0;
}
