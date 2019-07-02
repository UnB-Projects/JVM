#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include <vector>
#include "Instruction.hpp"
#include "ClassLoader.hpp"

using namespace std;

class InstructionSet {
private:
    Instruction instructionSet[256];
    uint32_t instructionsCount;
public:
    InstructionSet(ClassLoader*);
    Instruction * getInstructionSet() {
        return instructionSet;
    }
    uint32_t getInstructionsCount() {
        return instructionsCount;
    }
};

#endif