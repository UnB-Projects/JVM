#include "../hpp/Instruction.hpp"

Instruction::Instruction(string mnemonic, uint32_t bytesCount) {
    this->mnemonic = mnemonic;
    this->bytesCount = bytesCount;
}

void Instruction::setMnemonic(string mnemonic) {
    this->mnemonic = mnemonic;
}
string Instruction::getMnemonic() {
    return this->mnemonic;
}
void Instruction::setBytesCount(uint32_t bytesCount) {
    this->bytesCount = bytesCount;
}
uint32_t Instruction::getBytesCount() {
    return this->bytesCount;
}