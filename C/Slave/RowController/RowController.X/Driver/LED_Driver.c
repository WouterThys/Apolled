#include <pic18f2550.h>

#include "LED_Driver.h"


void ledDriverInit(uint8_t node_count) {
    // Set ports
}

void updateLeds(uint8_t r, uint8_t b, uint8_t g, uint8_t s) {
    // 1 - Deselect all
    PORTB = 0;
    
    // 2 - Set RGB output pins
    PORTAbits.RA0 = r;
    PORTAbits.RA1 = g;
    PORTAbits.RA2 = b;
    
    // 3 - Select new
    PORTB = 1 << s;
}