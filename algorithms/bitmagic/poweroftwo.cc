#include <iostream>

bool isPowerOfTwo(int x) {
	std::cout << x << !(x & (x - 1)) << std::endl;
	return x && (!(x & (x - 1)));
}

int main() {
		std::cout << isPowerOfTwo(10) << std::endl;
}
