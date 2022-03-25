#pragma once
#include <stdint.h>
#include <iostream>

class RAM
{
   
    int       offset;  // starting address in memory for RAM
    int       size;    // amount of bytes in the address space the RAM takes up
public:
    uint8_t  *memory;  // points to the array that the contents of the RAM are stored in
    RAM();
    ~RAM();
    void write(uint32_t addr, uint32_t data, int dataSize);
    uint32_t read(uint32_t addr, int dataSize);

};