#include "CPU.hpp"


CPU::CPU() : ram()
{
    
    reg = new uint32_t[4];
    PC = 0;
    SP = 0;
    flags = 0x00; // XXXXXZNC Z-Zero, N-Negative, C-Carry
    for(int i = 0; i < 4; i++)
        reg[i] = 0;

    
}   

CPU::~CPU()
{
    delete [] reg;
}

void CPU::clock()
{
    // std::cout << "PC: " << PC << "\n";
    // std::cout << "ram[pc]: " << (uint16_t)ram.memory[PC] << "\n";
    // std::cout << "opcode: " << std::hex << ram.read(PC, 4) << std::endl;

    uint8_t opcodeByte1 = ram.read(PC, 1);
    PC++;
    
    
    // if the first 2 bits of the first byte of the opcode are 00, then the opcode has 2 bytes, if the third bit is 0, the opcode has 3 bytes, all other cases, it is one byte
    if(opcodeByte1 & 0xc0 >> 6 == 0b00) // check if there is a second byte
    {
        uint8_t opcodeByte2 = ram.read(PC, 1);
        PC++;
        if(opcodeByte1 & 0x20 == 0b0) // check if there is a third byte
        {
            uint8_t opcodeByte3 = ram.read(PC, 1);
            PC++;
            //opcode has 3 bytes
        } 
        else 
        {
            // opcode has 2 bytes
        }
    } 
    else 
    {
        if(opcodeByte1 == 0xd7) // simple test opcode, writes a word into an address
        {
            //fetch memory address as operand
            uint32_t operand = ram.read(PC, 4);
            PC += 4;
            uint16_t data = ram.read(PC, 2);
            PC += 2;
            ram.write(operand, data, 2);
            std::cout << "0xd7 called!\n";
        }
    }
    
}

    
