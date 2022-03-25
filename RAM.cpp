#include "RAM.hpp"

RAM::RAM()
{

    this->offset  = 0;
    this->size    = 0x400000;
    this->memory  = new uint8_t[size]; // RAM will take up to whole address space for now (will be changed later when more components are added)
    for(int i = 0; i < size; i++)
        memory[i] = 0;
    
    
}

RAM::~RAM()
{
    std::cout << "deleted RAM!" << std::endl;
    delete [] memory;
}


uint32_t RAM::read(uint32_t addr, int dataSize)
{
    uint32_t value = 0;
    if(addr >= offset && addr < size + offset) // make sure address is in range of memory
    {
        for(int i = 0; i < dataSize; i++) // get each byte in the word
        {
            value += memory[(addr-offset+i) % (size)] << ((8 * dataSize - 8) - i * 8); // convert the bytes to big-endian from memory
        }
    }
    return value;
} 

void RAM::write(uint32_t addr, uint32_t data, int dataSize)
{
    if(addr >= offset && addr < offset + size) // make sure address is in range of memory
    {
        for(int i = 0; i < dataSize; i++) // write each byte into RAM
        {
            memory[addr - offset + i] = (data & (0xff << (i * 8))) >> (i * 8); // convert to little-endian
        }
    }
} 