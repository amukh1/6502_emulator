#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "./6502.h"

int main() {
    std::vector<DATA> mem_temp = std::vector<DATA>(65536, 0);
    std::vector<DATA>* mem = &mem_temp;
    (mem_temp)[0xFFFC] = 0x02;

    _6502 processor(mem);
    processor.reset(); // call reset sequence

    processor.A = 0xFF;
    processor.push();
    processor.push();

    std::ofstream out("out.bin", std::ios::out | std::ios::binary);
    DATA* mem_arr = mem_temp.data();
    out.write((char*)mem_arr, mem_temp.size());
    out.close();

    // processor.log();
}