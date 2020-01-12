#include "template.hh"
#include <iostream>

int main() {
	Template<int> obj;

	obj.set(2);

	std::cout << obj.get() << std::endl;
	return 0;
}
