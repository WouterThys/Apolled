#ifndef LED_DRIVER_H
#define	LED_DRIVER_H

#include <stdint.h>

/**
 * Initialize driver
 * @param node_count number of selectable lines
 */
void ledDriverInit(uint8_t node_count);

/**
 * Update LED pins
 * @param r Red value on or off
 * @param b Blue value on or off
 * @param g Green value on or off
 * @param s Selected line
 */
void updateLeds(uint8_t r, uint8_t b, uint8_t g, uint8_t s);


#endif	/* LED_DRIVER_H */

