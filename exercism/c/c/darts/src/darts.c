#include "darts.h"
#include <math.h>
#include <stdio.h>

// outer circle - 10 radius 
// middle circle - 5 radius
// inner circle - 1 radius
uint8_t score(coordinate_t points) {

	float res = sqrt(points.x * points.x + points.y * points.y);

	if (res <= 1) {
		return 10;
	} else if (res <= 5) {
		return 5; 
	} else if (res <= 10) {
		return 1;
	} else {
		return 0;
	}
}
