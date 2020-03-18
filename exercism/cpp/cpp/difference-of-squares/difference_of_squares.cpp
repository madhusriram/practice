#include "difference_of_squares.h"

namespace difference_of_squares {
	unsigned square_of_sum(unsigned num) {
		unsigned sum = (num * (num + 1)) / 2;
		return sum * sum;
	}

	unsigned sum_of_squares(unsigned num) {
		unsigned res = 0;

		for (unsigned i = 1; i <= num; num++) {
			res += i * i;
		}
		return res;
	}

	unsigned difference(unsigned num) {
		return square_of_sum(num) - sum_of_squares(num);
	}

}  // namespace difference_of_squares
