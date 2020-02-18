#include "resistor_color.h"

resistor_band_t cols[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE,
	 VIOLET, GREY, WHITE};

int color_code(resistor_band_t color) {
	return cols[color];
}

resistor_band_t *colors() {
	return cols;	
}
