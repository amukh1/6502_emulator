#include <vector>
#include <memory>
#include <cstdint>
#include <fstream>
#include <map>

const std::map<int, int[]> opcode_dict = {
    {"LDA", {0xA9, 0xAD, 0xBD, 0xB9, 0xA5, 0xB5, 0xA1, 0xB1 }},
    {"LDX", {0xA2}}
};


#include "./6502.h"

_6502::_6502(std::vector<DATA>* mem) {
    this->memory = mem;
}

void _6502::reset() {
    this->PC = (this->read(0xFFFC) << 8) | (this->read(0xFFFD));
    this->S = 0x01FF;
    this->P = 0x24; // 0b00100100
    this->A = 0;
    this->X = 0;
    this->Y = 0;
}

DATA _6502::read(ADDRESS add) {
    return (*this->memory)[add];
}

void _6502::write(DATA data, ADDRESS add) {
    (*this->memory)[add] = data;
}

void _6502::push() {
    this->write(this->A, this->S);
    this->S--;
}

void _6502::pop() {
    this->S++;
    this->A = this->read(this->S);
    this->write(0,this->S);
}

void _6502::IRQ() {
    
}

void _6502::NMI() {
    
}

void _6502::tick() {

}

void _6502::log() {
    std::ofstream log("logs.txt", std::ios::out);
    
    log.write("----", 4);
    log.close();
}