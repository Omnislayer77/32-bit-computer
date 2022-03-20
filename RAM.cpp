#include "RAM.hpp"

RAM::RAM(uint8_t *dataBus, uint32_t *addrBus)
{
    this->addrBus = addrBus;
    this->dataBus = dataBus;
    this->offset  = 0;
    this->size    = 0x400000;
    this->memory  = new uint8_t [size]; // RAM will take up to whole address space for now (will be changed later when more component are added)
    
}

void RAM::clock(bool RW) // executed once per clock cycle
{
    if(*addrBus >= offset && *addrBus < size) // check to make sure address is in range for ram
    {
        if(RW == false) // RW being false means that the PROCESSOR is currently reading (RAM is writing)
            *dataBus = memory[(*addrBus - offset)];
        else // when RW is true, the processor is writing to memory 
            memory[(*addrBus - offset)] = *dataBus;
    }
    std::cout << (int)memory[0x42069] << "\n";
}   
