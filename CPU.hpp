#pragma once
#include "RAM.hpp"
#include <stdint.h>


class CPU
{
    
    uint32_t *reg;
    uint32_t PC;
    uint32_t SP;
    uint8_t flags;
  
public:
    RAM ram;
    CPU();
    ~CPU();
    void clock();
};