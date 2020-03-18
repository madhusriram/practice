#include "reverse_string.h"

namespace reverse_string {
	std::string reverse_string(std::string &input) {
		int len = input.length();
		for (int i = 0; i < len/2; i++) {
			char c = input[i];
			input[i] = input[len-i-1];
			input[len-i-1] = c;
		}
		return input;
	}
}  // namespace reverse_string
