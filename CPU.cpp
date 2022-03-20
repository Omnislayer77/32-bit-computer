#include "CPU.hpp"


CPU::CPU(uint8_t *dataBus, uint32_t *addrBus)
{
    this->dataBus = dataBus;
    this->addrBus = addrBus;
    RW = false;
}

    
