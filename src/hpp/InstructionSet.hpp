#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include <vector>
#include "Instruction.hpp"

using namespace std;

class InstructionSet {
private:
    Instruction * instructionSet;
    uint32_t instructionsCount;
public:
    InstructionSet();
    Instruction * getInstructionSet() {
        return instructionSet;
    }
    uint32_t getInstructionsCount() {
        return instructionsCount;
    }
};

#endif