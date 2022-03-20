#pragma once
#include <stdint.h>


class CPU
{
    bool      RW;      // read-write, used for telling other components wether the CPU is reading or writing to the address space, false = reading, true = writing
    uint8_t  *dataBus; // although its a 32-bit computer, the bus and adrress space will deal in bytes to make storage more effiecent
    uint32_t *addrBus; // yup, we given this fucker a 4 megabytes of addressing space.

public:
    CPU(uint8_t *dataBus, uint32_t *addrBus);
};