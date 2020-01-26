#include <stdio.h>

#define LEN 1000

// swap using temp
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// returns the new length of the array
// Algorithm:
// - Run the algorithm until the point when the right pointer reaches the 
//   end of the array
// - Move left and right poiters together until
//		- left == to be removed number
//		- move the right pointer to find the number to swap with left
//		- if found swap and start left and right together again
//		- else, quit
//   catches up start moving both pointers
// Move left and right pointers together until we
int removeElement(int arrSize, int *arr, int removeNum) {
	int newLen = 0;
	int *left = arr;
	int *right = arr;

	// null pointer
	if (! arr)
		return -1;

	// 2 1 2
	for (newLen = 0; *right != '\0'; newLen++) {
		if (*left == removeNum) {
			while (*right != '\0') {
				if (*right != removeNum) {
					swap(left, right);
					right = left;
					break;
				}
				right++;
			}
		}	

		// best-case
		left++;
		right++;
	}
	return newLen - 1;
}

int main() {
	int s[LEN];
	int n;
	int removeNum;
	int i;

	printf("Enter the array length: ");
	scanf("%d", &n);

	printf("Enter the integer array: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	s[i] = '\0';

	printf("Enter the number to be removed in-place: ");
	scanf("%d", &removeNum);

	int newLen = removeElement(n, s, removeNum);

	for (i = 0; i < newLen; i++) {
		printf("%d ", s[i]);
	}

	printf("\n");

	printf("New length of the array: %d\n", newLen);


	return 0;	
}
