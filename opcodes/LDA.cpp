#include <vector>
#include <memory>
#include <cstdint>
#include <fstream>

#include "../6502.h"

void _6502::LDA(DATA opcode) {
    switch(opcode) {
        case 0xA9:
        this->A = this->read(this->PC+1);
        this->PC+=2;
        break;
        case 0xAD:
        this->A = this->read((this->read(this->PC+2) << 8) | this->read(this->PC+1));
        this->PC+=3;
        break;
        case 0xBD:
        this->A = this->read(((this->read(this->PC+2) << 8) | this->read(this->PC+1)) + this->X);
        this->PC+=3;
        break;
        case 0xB9:
        this->A = this->read(((this->read(this->PC+2) << 8) | this->read(this->PC+1)) + this->Y);
        this->PC+=3;
        break;
        case 0xA5:
        this->A = this->read((0 << 8) | this->read(this->PC+1))
        this->PC+=2;
        break;
        case 0xB5:
        this->A = this->read(((0 << 8) | this->read(this->PC+1))+this->X)
        this->PC+=2;
        break;
        case 0xA1:
        this->A = this->read(
            this->read((((0 << 8) | this->read(this->PC+1)) + this->X) & 0xFF)
        )
        break;
        case 0xB1:
        DATA op = this->read(this->PC+1)
        // OP 02
        // 02 -> 1
        // 03 -> 2
        // (2,1)+Y -> 3
        // A = 3
        this->A = this->read(
            ((this->read(op+1) << 8) | this->read(op))+this->Y
        )
        break;
    }
}