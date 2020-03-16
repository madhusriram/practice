#include "hello_world.h"

// Use everything from the 'std' namespace.
// This lets us write 'string' instead of 'std::string'.
using namespace std;

namespace hello_world {

string hello() {
    return "Hello, World!";
}

}  // namespace hello_world
