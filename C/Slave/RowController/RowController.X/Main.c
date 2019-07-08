#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../../Common/Common.h"
#include "Driver/LED_Driver.h"

/*******************************************************************************
 *          DEFINES
 ******************************************************************************/
#define _XTAL_FREQ 16000000

/*******************************************************************************
 *          MACRO FUNCTIONS
 ******************************************************************************/
#define GetBit(n, k) ((uint8_t)((n & ( 1 << k )) >> k))

/*******************************************************************************
 *          DEFINES
 ******************************************************************************/


/*******************************************************************************
 *          VARIABLES
 ******************************************************************************/
Row_t row;

/*******************************************************************************
 *          LOCAL FUNCTIONS
 ******************************************************************************/
void initRowConfig(Row_t* config, uint8_t count);
void tick();

/*******************************************************************************
 *          MAIN PROGRAM
 ******************************************************************************/
void main(void) {
    
    initRowConfig(&row, 5);
    ledDriverInit(5);
    
    while(1) {
        
        // TODO: with timer
        tick();
        __delay_ms(1);
    }
    return;
}

void tick() {
    
    
    RGBNode_t node = row.node_array[row.selected_node];
    uint8_t r = GetBit(node.R, row.rgb_bit_shift);
    uint8_t g = GetBit(node.G, row.rgb_bit_shift);
    uint8_t b = GetBit(node.B, row.rgb_bit_shift);
    
    // Update LED driver with rgb values
    updateLeds(r, g, b, row.selected_node);
    
    // Move to next node, when nodes are done loop back to first
    row.selected_node++;
    if (row.selected_node >= row.node_count) {
        row.selected_node = 0;
        
        // Move to next bit, when all 4 bits are shifted, loop back
        row.rgb_bit_shift++;
        if (row.rgb_bit_shift >= 4) {
            row.rgb_bit_shift = 0;
        }
    }
    
}

void initRowConfig(Row_t* config, uint8_t count) {
    config->node_count = count;
    config->selected_node = 0;
    uint8_t i;
    for (i = 0; i < count; i++) {
        config->node_array[i].R = 0;
        config->node_array[i].G = 0;
        config->node_array[i].B = 0;
        config->node_array[i].config = 0;
    }
}