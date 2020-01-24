#include <iostream>

using namespace std;

// factorial of a very large number, the result of which cannot be put in any
// primitive data type

#define MAX_SIZE 1000

// returns the msb index
int multiply(int *arr, int multiplier, int msd) {
	int carry = 0;
	int i = 0;

	// start from the 0th index and start multiplying with the multiplier
	for (i = 0; i <= msd; i++ ) {
		int multiplicand = arr[i];

		int res = multiplicand * multiplier + carry;
		arr[i] = res % 10;
		carry = res / 10;
	}

	// add back the carry if > 0
	while (carry) {
		arr[i] = carry % 10;
		carry = carry / 10;
		msd = i;
		i++;
	}

	return msd;
}

int main() {
	cout << "Enter factorial to calculate: ";
	int n;
	cin >> n;
	int arr[MAX_SIZE] = {0};

	// most significant digit, starts from 0th index
	int msd = 0;

	// start with a base value, 0! == 1 as well!
	arr[0] = 1;

	for (int i = 2; i <= n; i++) {
		msd = multiply(arr, i, msd);
	}

	// print result
	for (; msd >= 0; msd--) {
		cout << arr[msd];
	}
	cout << endl;
}
