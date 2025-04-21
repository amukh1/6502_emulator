#pragma once

#include <vector>
#include <memory>
#include <cstdint>

#define DATA uint8_t
#define ADDRESS uint16_t

struct _6502 {
    std::vector<DATA>* memory;

    uint16_t PC;
    uint8_t A = 0;
    uint8_t X = 0;
    uint8_t Y = 0;
    uint16_t S = 0;
    uint8_t P = 0;

    _6502(std::vector<DATA>* mem);

    // TODO: Other 2 interupts
    void reset();
    DATA read(ADDRESS add);
    void write(DATA data, ADDRESS add);
    void tick();

    void push();
    void pop();

    void LDA(DATA opcode);

    void log();
};