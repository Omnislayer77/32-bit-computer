#pragma once
#include <stdint.h>
#include <iostream>

class RAM
{
    uint8_t  *memory;  // points to the array that the contents of the RAM are stored in
    uint8_t  *dataBus;  
    uint32_t *addrBus;
    int       offset;  // starting address in memory for RAM
    int       size;    // amount of bytes in the address space the RAM takes up
public:
    RAM(uint8_t *dataBus, uint32_t *addrBus);

    void clock(bool RW); // executed once per clock cycle 
};