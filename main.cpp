#include <iostream>
#include <chrono>
#include <stdint.h>
#include "CPU.hpp"
#include "RAM.hpp"

int main()
{
	auto programStart = std::chrono::high_resolution_clock::now();

	double clockSpeed = 1; // clock speed in hz
	
	CPU cpu = CPU();

	for(;;)
	{
		auto cycleStart = std::chrono::high_resolution_clock::now();
		cpu.clock();

		

		//timing code, slows the program down to the predefined clock speed
		auto now = std::chrono::high_resolution_clock::now();
		while(std::chrono::duration_cast<std::chrono::microseconds>(now-cycleStart).count() < (1/clockSpeed) * 1e6)
			now = std::chrono::high_resolution_clock::now();

	}
	std::cout << "Program Exit" << std::endl;
	return 0;
}
