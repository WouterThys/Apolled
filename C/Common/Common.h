#ifndef COMMON_H
#define	COMMON_H

#include <stdint.h>

// Types
typedef union {
    struct {
        // 4 bit RGB values - 16 values / color
        uint8_t R : 4;  
        uint8_t G : 4;
        uint8_t B : 4;
        // 4 bit config
        uint8_t config : 4;
    };
    // Register value
    uint16_t value;
} RGBNode_t ;

typedef struct {
    
    uint8_t     node_count;     // Number of nodes
    RGBNode_t   node_array[5];  // Node array (max 5)
    
    // Some usefull data
    uint8_t     selected_node;  // Current node array index
    uint8_t     rgb_bit_shift;  // Shift counter for RGB values
    
} Row_t ;

//     



#endif	/* SETTINGS_H */