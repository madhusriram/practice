#include "resistor_color_trio.h"

#include <stdio.h>


unsigned int power_of_10(int exponent) {
	unsigned int res = 1;

	for ( ; exponent > 0 ; exponent--) {
		res = res * 10;
	}
	return res;
}

resistor_value_t color_code(resistor_band_t *band) {
	resistor_band_t unit = band[2];
	unsigned int pow_res = power_of_10(unit);
	resistor_value_t res;

	res.value = (band[0] * 10 + band[1] * 1) * (pow_res);
	
	if (res.value % 1000  == 0) {
		res.value /= 1000;
		res.unit = KILOOHMS;
	} else {
		res.unit = OHMS;
	}
	return res;
}
