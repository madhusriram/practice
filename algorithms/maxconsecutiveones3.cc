#include <iostream>

// https://leetcode.com/problems/max-consecutive-ones-iii/
// Medium - sliding windown problem

// in this approach I reset the right window back to the left window if max 
// transitions have appeared. The optimization would be to leave the right
// window as is, moving the left window by 1 and adjusting the transition
// count appropriately.
int main() {
	const int arr[] = {1,1,1,0,0,0,1,1,1,1,0};
	int K = 2;
	int changed = 0;
	int max_len = 0;
	int saved_max_len = 0;

	int arr_len = sizeof(arr)/sizeof(arr[0]);

	// indices that'd move like a window
	// left would move forward only when 0->1 transitions exceed K
	int left = 0;
	int right = 0;

	while (right < arr_len) {
		if (arr[right] && 1) {
			max_len++;
			right++;	
		} else if (changed < K) {		// must be a 0
			changed++;
			max_len++;
			right++;
		} else {			// max transitions have happened, move left and reset right
			left++;
			right = left;
			changed = 0;
			max_len = 0;
		}
	
		if (max_len > saved_max_len) 
			saved_max_len = max_len;
	}

	printf("Consecutive one's: %d\n", saved_max_len); 

	return 0;
}
