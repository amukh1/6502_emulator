#include <vector>
#include <memory>
#include <cstdint>
#include <fstream>

#include "../6502.h"

void _6502::LDA(DATA opcode) {
    switch(opcode) {
        case 0xA9:
        processor.A = processor.read(processor.PC+1);
        processor.PC+=2;
        break;
        case 0xAD:
        processor.A = processor.read((processor.read(processor.PC+1) << 8) | processor.read(processor.PC+2));
        processor.PC+=3;
        break;
        case 0xBD:

        break;
        case 0xB9:

        break;
        case 0xA5:

        break;
        case 0xB5:

        break;
        case 0xA1:

        break;
        case 0xB1:

        break;
    }
}