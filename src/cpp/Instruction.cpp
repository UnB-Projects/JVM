#include "../hpp/Instruction.hpp"

Instruction::Instruction() {
    //Para declarar sem argumentos
}


Instruction::Instruction(string mnemonic, uint32_t bytesCount, uint32_t (*func)(Frame*)) {
    this->mnemonic = mnemonic;
    this->bytesCount = bytesCount;
    this->func = func;
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

uint32_t Instruction::nopFunction(Frame* frame) {
    printf("Instrucao nopFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::aconst_nullFunction(Frame* frame) {
    printf("Instrucao aconst_nullFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_m1Function(Frame* frame) {
    printf("Instrucao iconst_m1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_0Function(Frame* frame) {
    printf("Instrucao iconst_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_1Function(Frame* frame) {
    printf("Instrucao iconst_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_2Function(Frame* frame) {
    printf("Instrucao iconst_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_3Function(Frame* frame) {
    printf("Instrucao iconst_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_4Function(Frame* frame) {
    printf("Instrucao iconst_4Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iconst_5Function(Frame* frame) {
    printf("Instrucao iconst_5Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lconst_0Function(Frame* frame) {
    printf("Instrucao lconst_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lconst_1Function(Frame* frame) {
    printf("Instrucao lconst_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fconst_0Function(Frame* frame) {
    printf("Instrucao fconst_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fconst_1Function(Frame* frame) {
    printf("Instrucao fconst_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fconst_2Function(Frame* frame) {
    printf("Instrucao fconst_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dconst_0Function(Frame* frame) {
    printf("Instrucao dconst_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dconst_1Function(Frame* frame) {
    printf("Instrucao dconst_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::bipushFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte = bytecode[++frame->localPC];
    JavaType value;

    value.type_int = (int32_t)byte;
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::sipushFunction(Frame* frame) {
    printf("Instrucao sipushFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ldcFunction(Frame* frame) {
    uint8_t * bytecode = frame->getCode();
    uint8_t byte = bytecode[++frame->localPC];
    uint8_t index = byte;
    JavaType value;

    CPInfo * cpInfo = frame->constantPool[index-1];
    switch(cpInfo->getTag()) {
    // case CPInfo::CONSTANT_Class:
    //     break;
    // case CPInfo::CONSTANT_Methodref:
    //     break;
    // case CPInfo::CONSTANT_MethodHandle:
    //     break;
    case CPInfo::CONSTANT_String:
        value.type_reference = (uint64_t)new string(cpInfo->getInfo(frame->constantPool).first);
        frame->operandStack.push(value);
        break;
    case CPInfo::CONSTANT_Integer:
        value.type_int = cpInfo->getIntegerInfo().bytes;
        frame->operandStack.push(value);
        break;
    case CPInfo::CONSTANT_Float:
        value.type_float = cpInfo->getFloatNumber();
        frame->operandStack.push(value);
        break;
    default:
        printf("A funcao ldc encontrou um tipo indefinido: %d\n", cpInfo->getTag());
        exit(0);
        break;
    }
    return ++frame->localPC;
}

uint32_t Instruction::ldc_wFunction(Frame* frame) {
    printf("Instrucao ldc_wFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ldc2_wFunction(Frame* frame) {
    uint8_t * bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    JavaType value;

    CPInfo * cpInfo = frame->constantPool[index-1];
    switch(cpInfo->getTag()) {
    case CPInfo::CONSTANT_Long:
        value.type_long = ((uint64_t)cpInfo->getLongInfo().high_bytes << 32) | cpInfo->getLongInfo().low_bytes;
        frame->operandStack.push(value);
        break;
    case CPInfo::CONSTANT_Double:
        value.type_double = ((uint64_t)cpInfo->getDoubleInfo().high_bytes << 32) | cpInfo->getDoubleInfo().low_bytes;
        frame->operandStack.push(value);
        break;
    default:
        printf("A funcao ldc2_w encontrou um tipo indefinido: %d\n", cpInfo->getTag());
        exit(0);
        break;
    }
    return ++frame->localPC;
}
uint32_t Instruction::iloadFunction(Frame* frame) {
    printf("Instrucao iloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lloadFunction(Frame* frame) {
    printf("Instrucao lloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::floadFunction(Frame* frame) {
    printf("Instrucao floadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dloadFunction(Frame* frame) {
    printf("Instrucao dloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::aloadFunction(Frame* frame) {
    printf("Instrucao aloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iload_0Function(Frame* frame) {
    printf("Instrucao iload_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iload_1Function(Frame* frame) {
    printf("Instrucao iload_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iload_2Function(Frame* frame) {
    printf("Instrucao iload_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iload_3Function(Frame* frame) {
    printf("Instrucao iload_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lload_0Function(Frame* frame) {
    printf("Instrucao lload_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lload_1Function(Frame* frame) {
    printf("Instrucao lload_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lload_2Function(Frame* frame) {
    printf("Instrucao lload_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lload_3Function(Frame* frame) {
    printf("Instrucao lload_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fload_0Function(Frame* frame) {
    printf("Instrucao fload_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fload_1Function(Frame* frame) {
    printf("Instrucao fload_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fload_2Function(Frame* frame) {
    printf("Instrucao fload_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fload_3Function(Frame* frame) {
    printf("Instrucao fload_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dload_0Function(Frame* frame) {
    printf("Instrucao dload_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dload_1Function(Frame* frame) {
    printf("Instrucao dload_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dload_2Function(Frame* frame) {
    printf("Instrucao dload_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dload_3Function(Frame* frame) {
    printf("Instrucao dload_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::aload_0Function(Frame* frame) {
    printf("Instrucao aload_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::aload_1Function(Frame* frame) {
    JavaType objectref;

    objectref.type_reference = frame->localVariables[1].type_reference;
    frame->operandStack.push(objectref);

    return ++frame->localPC;
}
uint32_t Instruction::aload_2Function(Frame* frame) {
    JavaType objectref;

    objectref.type_reference = frame->localVariables[2].type_reference;
    frame->operandStack.push(objectref);

    return ++frame->localPC;
}
uint32_t Instruction::aload_3Function(Frame* frame) {
    printf("Instrucao aload_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ialoadFunction(Frame* frame) {
    printf("Instrucao ialoadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::laloadFunction(Frame* frame) {
    printf("Instrucao laloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::faloadFunction(Frame* frame) {
    printf("Instrucao faloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::daloadFunction(Frame* frame) {
    printf("Instrucao daloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::aaloadFunction(Frame* frame) {
    printf("Instrucao aaloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::baloadFunction(Frame* frame) {
    printf("Instrucao baloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::caloadFunction(Frame* frame) {
    printf("Instrucao caloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::saloadFunction(Frame* frame) {
    printf("Instrucao saloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::istoreFunction(Frame* frame) {
    printf("Instrucao istoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lstoreFunction(Frame* frame) {
    printf("Instrucao lstoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fstoreFunction(Frame* frame) {
    printf("Instrucao fstoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dstoreFunction(Frame* frame) {
    printf("Instrucao dstoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::astoreFunction(Frame* frame) {
    printf("Instrucao astoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::istore_0Function(Frame* frame) {
    printf("Instrucao istore_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::istore_1Function(Frame* frame) {
    printf("Instrucao istore_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::istore_2Function(Frame* frame) {
    printf("Instrucao istore_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::istore_3Function(Frame* frame) {
    printf("Instrucao istore_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lstore_0Function(Frame* frame) {
    printf("Instrucao lstore_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lstore_1Function(Frame* frame) {
    printf("Instrucao lstore_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lstore_2Function(Frame* frame) {
    printf("Instrucao lstore_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lstore_3Function(Frame* frame) {
    printf("Instrucao lstore_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fstore_0Function(Frame* frame) {
    printf("Instrucao fstore_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fstore_1Function(Frame* frame) {
    printf("Instrucao fstore_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fstore_2Function(Frame* frame) {
    printf("Instrucao fstore_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fstore_3Function(Frame* frame) {
    printf("Instrucao fstore_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dstore_0Function(Frame* frame) {
    printf("Instrucao dstore_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dstore_1Function(Frame* frame) {
    printf("Instrucao dstore_1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dstore_2Function(Frame* frame) {
    printf("Instrucao dstore_2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dstore_3Function(Frame* frame) {
    printf("Instrucao dstore_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::astore_0Function(Frame* frame) {
    printf("Instrucao astore_0Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::astore_1Function(Frame* frame) {
    JavaType objectref;

    objectref.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[1] = objectref;

    return ++frame->localPC;
}
uint32_t Instruction::astore_2Function(Frame* frame) {
    JavaType objectref;

    objectref.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[2] = objectref;

    return ++frame->localPC;
}
uint32_t Instruction::astore_3Function(Frame* frame) {
    printf("Instrucao astore_3Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iastoreFunction(Frame* frame) {
    printf("Instrucao iastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lastoreFunction(Frame* frame) {
    printf("Instrucao lastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fastoreFunction(Frame* frame) {
    printf("Instrucao fastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dastoreFunction(Frame* frame) {
    printf("Instrucao dastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::aastoreFunction(Frame* frame) {
    printf("Instrucao aastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::bastoreFunction(Frame* frame) {
    printf("Instrucao bastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::castoreFunction(Frame* frame) {
    printf("Instrucao castoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::sastoreFunction(Frame* frame) {
    printf("Instrucao sastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::popFunction(Frame* frame) {
    printf("Instrucao popFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::pop2Function(Frame* frame) {
    printf("Instrucao pop2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dupFunction(Frame* frame) {
    JavaType duplicated = frame->operandStack.top();
    frame->operandStack.pop();
    frame->operandStack.push(duplicated);
    frame->operandStack.push(duplicated);

    return ++frame->localPC;
}
uint32_t Instruction::dup_x1Function(Frame* frame) {
    printf("Instrucao dup_x1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dup_x2Function(Frame* frame) {
    printf("Instrucao dup_x2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dup2Function(Frame* frame) {
    printf("Instrucao dup2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dup2_x1Function(Frame* frame) {
    printf("Instrucao dup2_x1Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dup2_x2Function(Frame* frame) {
    printf("Instrucao dup2_x2Function nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::swapFunction(Frame* frame) {
    printf("Instrucao swapFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iaddFunction(Frame* frame) {
    printf("Instrucao iaddFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::laddFunction(Frame* frame) {
    printf("Instrucao laddFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::faddFunction(Frame* frame) {
    printf("Instrucao faddFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::daddFunction(Frame* frame) {
    printf("Instrucao daddFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::isubFunction(Frame* frame) {
    printf("Instrucao isubFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lsubFunction(Frame* frame) {
    printf("Instrucao lsubFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fsubFunction(Frame* frame) {
    printf("Instrucao fsubFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dsubFunction(Frame* frame) {
    printf("Instrucao dsubFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::imulFunction(Frame* frame) {
    printf("Instrucao imulFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lmulFunction(Frame* frame) {
    printf("Instrucao lmulFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fmulFunction(Frame* frame) {
    printf("Instrucao fmulFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dmulFunction(Frame* frame) {
    printf("Instrucao dmulFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::idivFunction(Frame* frame) {
    printf("Instrucao idivFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ldivOpFunction(Frame* frame) {
    printf("Instrucao ldivOpFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fdivFunction(Frame* frame) {
    printf("Instrucao fdivFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ddivFunction(Frame* frame) {
    printf("Instrucao ddivFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iremFunction(Frame* frame) {
    printf("Instrucao iremFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lremFunction(Frame* frame) {
    printf("Instrucao lremFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fremFunction(Frame* frame) {
    printf("Instrucao fremFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dremFunction(Frame* frame) {
    printf("Instrucao dremFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::inegFunction(Frame* frame) {
    printf("Instrucao inegFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lnegFunction(Frame* frame) {
    printf("Instrucao lnegFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fnegFunction(Frame* frame) {
    printf("Instrucao fnegFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dnegFunction(Frame* frame) {
    printf("Instrucao dnegFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ishlFunction(Frame* frame) {
    printf("Instrucao ishlFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lshlFunction(Frame* frame) {
    printf("Instrucao lshlFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ishrFunction(Frame* frame) {
    printf("Instrucao ishrFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lshrFunction(Frame* frame) {
    printf("Instrucao lshrFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iushrFunction(Frame* frame) {
    printf("Instrucao iushrFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lushrFunction(Frame* frame) {
    printf("Instrucao lushrFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iandFunction(Frame* frame) {
    printf("Instrucao iandFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::landFunction(Frame* frame) {
    printf("Instrucao landFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iorFunction(Frame* frame) {
    printf("Instrucao iorFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lorFunction(Frame* frame) {
    printf("Instrucao lorFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ixorFunction(Frame* frame) {
    printf("Instrucao ixorFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lxorFunction(Frame* frame) {
    printf("Instrucao lxorFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::iincFunction(Frame* frame) {
    printf("Instrucao iincFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::i2lFunction(Frame* frame) {
    printf("Instrucao i2lFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::i2fFunction(Frame* frame) {
    printf("Instrucao i2fFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::i2dFunction(Frame* frame) {
    printf("Instrucao i2dFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::l2iFunction(Frame* frame) {
    printf("Instrucao l2iFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::l2fFunction(Frame* frame) {
    printf("Instrucao l2fFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::l2dFunction(Frame* frame) {
    printf("Instrucao l2dFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::f2iFunction(Frame* frame) {
    printf("Instrucao f2iFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::f2lFunction(Frame* frame) {
    printf("Instrucao f2lFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::f2dFunction(Frame* frame) {
    printf("Instrucao f2dFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::d2iFunction(Frame* frame) {
    printf("Instrucao d2iFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::d2lFunction(Frame* frame) {
    printf("Instrucao d2lFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::d2fFunction(Frame* frame) {
    printf("Instrucao d2fFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::i2bFunction(Frame* frame) {
    printf("Instrucao i2bFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::i2cFunction(Frame* frame) {
    printf("Instrucao i2cFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::i2sFunction(Frame* frame) {
    printf("Instrucao i2sFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lcmpFunction(Frame* frame) {
    printf("Instrucao lcmpFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fcmplFunction(Frame* frame) {
    printf("Instrucao fcmplFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::fcmpgFunction(Frame* frame) {
    printf("Instrucao fcmpgFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dcmplFunction(Frame* frame) {
    printf("Instrucao dcmplFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dcmpgFunction(Frame* frame) {
    printf("Instrucao dcmpgFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifeqFunction(Frame* frame) {
    printf("Instrucao ifeqFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifneFunction(Frame* frame) {
    printf("Instrucao ifneFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifltFunction(Frame* frame) {
    printf("Instrucao ifltFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifgeFunction(Frame* frame) {
    printf("Instrucao ifgeFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifgtFunction(Frame* frame) {
    printf("Instrucao ifgtFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifleFunction(Frame* frame) {
    printf("Instrucao ifleFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_icmpeqFunction(Frame* frame) {
    printf("Instrucao if_icmpeqFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_icmpneFunction(Frame* frame) {
    printf("Instrucao if_icmpneFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_icmpltFunction(Frame* frame) {
    printf("Instrucao if_icmpltFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_icmpgeFunction(Frame* frame) {
    printf("Instrucao if_icmpgeFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_icmpgtFunction(Frame* frame) {
    printf("Instrucao if_icmpgtFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_icmpleFunction(Frame* frame) {
    printf("Instrucao if_icmpleFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_acmpeqFunction(Frame* frame) {
    printf("Instrucao if_acmpeqFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::if_acmpneFunction(Frame* frame) {
    printf("Instrucao if_acmpneFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::gotoOpFunction(Frame* frame) {
    printf("Instrucao gotoOpFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::jsrFunction(Frame* frame) {
    printf("Instrucao jsrFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::retFunction(Frame* frame) {
    printf("Instrucao retFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::tableswitchFunction(Frame* frame) {
    printf("Instrucao tableswitchFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lookupswitchFunction(Frame* frame) {
    printf("Instrucao lookupswitchFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ireturnFunction(Frame* frame) {
    printf("Instrucao ireturnFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::lreturnFunction(Frame* frame) {
    printf("Instrucao lreturnFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::freturnFunction(Frame* frame) {
    printf("Instrucao freturnFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::dreturnFunction(Frame* frame) {
    printf("Instrucao dreturnFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::areturnFunction(Frame* frame) {
    printf("Instrucao areturnFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::returnOpFunction(Frame* frame) {
    if (!frame->operandStack.empty()) {
        printf("A pilha de operandos nao esta vazia! Pode haver erros!\n");
    }
    return frame->localPC;
}
uint32_t Instruction::getstaticFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];

    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;

    if (className.compare("java/lang/System") == 0) {
        // JavaType javaType;
        // javaType.type_empty = 0xF0CAF0FA;
        // frame->operandStack.push(javaType);
        return ++frame->localPC;
    }

    printf("GetStatic ainda nao foi testada para outros casos alem do helloworld!\n");
    exit(0);


    // string nameAndType = frame->constantPool[index-1]->getInfo(frame->constantPool).second;
    // int j = 0;

    // while (j < nameAndType.size() && nameAndType[j+1] != ':') {
    //     j++;
    // }
    // string name = nameAndType.substr(0,j);
}
uint32_t Instruction::putstaticFunction(Frame* frame) {
    printf("Instrucao putstaticFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::getfieldFunction(Frame* frame) {
    printf("Instrucao getfieldFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::putfieldFunction(Frame* frame) {
    printf("Instrucao putfieldFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::invokevirtualFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];

    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;
    string nameAndType = frame->constantPool[index-1]->getInfo(frame->constantPool).second;
    int j = 0;

    while (j < nameAndType.size() && nameAndType[j+1] != ':') {
        j++;
    }
    string methodName = nameAndType.substr(0,j);
    string descriptor = nameAndType.substr(j+3,nameAndType.size());

    // Para debug
    // cout << className << " " << methodName << " " << descriptor << endl;

    if (className.compare("java/io/PrintStream") == 0) {
        if (methodName.compare("println") == 0) {
            if (descriptor.compare("(Ljava/lang/String;)V") == 0) {
                string* stringReference = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();
                cout << *stringReference << endl;
            }
            else if (descriptor.compare("(I)V") == 0) {
                int32_t integer = (int32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();
                cout << integer << endl;
            }
            else if (descriptor.compare("(F)V") == 0) {
                float floatNumber;
                memcpy(&floatNumber, &(frame->operandStack.top().type_float), sizeof(float));
                frame->operandStack.pop();
                cout << floatNumber << endl;
            }
            else if (descriptor.compare("(D)V") == 0) {
                double doubleNumber;
                memcpy(&doubleNumber, &(frame->operandStack.top().type_double), sizeof(double));
                frame->operandStack.pop();
                cout << doubleNumber << endl;
            }
            else if (descriptor.compare("(J)V") == 0) {
                int64_t longNumber = (int64_t)frame->operandStack.top().type_long;
                frame->operandStack.pop();
                cout << longNumber << endl;
            }
            else {
                printf("invokevirtualFunction: tipo do descritor nao reconhecido: %s\n", descriptor.c_str());
                exit(0);
            }
        }
        else {
            printf("invokevirtualFunction: falta implementar\n");
            exit(0);
        }
    }
    else {
        printf("invokevirtualFunction: falta implementar\n");
        exit(0);
    }

    return ++frame->localPC;


}
uint32_t Instruction::invokespecialFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];

    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;
    string nameAndType = frame->constantPool[index-1]->getInfo(frame->constantPool).second;
    int j = 0;

    while (j < nameAndType.size() && nameAndType[j+1] != ':') {
        j++;
    }
    string methodName = nameAndType.substr(0,j);
    string descriptor = nameAndType.substr(j+3,nameAndType.size());

    if (className.compare("java/lang/String") == 0) {
        if (methodName.compare("<init>") == 0) {
            string* stringReference = (string*)(frame->operandStack.top().type_reference);
            frame->operandStack.pop();
            string* initStringReference = (string*)(frame->operandStack.top().type_reference);
            frame->operandStack.pop();
            *initStringReference = *stringReference;
        }
        else {
            printf("invokespecial: metodo da classe string desconhecido: %s\n", methodName.c_str());
        }
    }
    else {
        printf("invokespecial: ainda nao esta funcionando caso nao seja string\n");
    }

    return ++frame->localPC;
}
uint32_t Instruction::invokestaticFunction(Frame* frame) {
    printf("Instrucao invokestaticFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::invokeinterfaceFunction(Frame* frame) {
    printf("Instrucao invokeinterfaceFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::invokedynamicFunction(Frame* frame) {
    printf("Instrucao invokedynamicFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::newOpFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];

    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;

    if (className.compare("java/lang/String") == 0) {
        JavaType objectref;
        objectref.type_reference = (uint64_t)new string("");
        frame->operandStack.push(objectref);
    }
    else {
        printf("newOp: ainda nao esta funcionando para casos alem de string do java\n");
    }
    return ++frame->localPC;
}
uint32_t Instruction::newarrayFunction(Frame* frame) {
    printf("Instrucao newarrayFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::anewarrayFunction(Frame* frame) {
    printf("Instrucao anewarrayFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::arraylengthFunction(Frame* frame) {
    printf("Instrucao arraylengthFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::athrowFunction(Frame* frame) {
    printf("Instrucao athrowFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::checkcastFunction(Frame* frame) {
    printf("Instrucao checkcastFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::instanceofFunction(Frame* frame) {
    printf("Instrucao instanceofFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::monitorenterFunction(Frame* frame) {
    printf("Instrucao monitorenterFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::monitorexitFunction(Frame* frame) {
    printf("Instrucao monitorexitFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::wideFunction(Frame* frame) {
    printf("Instrucao wideFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::multianewarrayFunction(Frame* frame) {
    printf("Instrucao multianewarrayFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifnullFunction(Frame* frame) {
    printf("Instrucao ifnullFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::ifnonnullFunction(Frame* frame) {
    printf("Instrucao ifnonnullFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::goto_wFunction(Frame* frame) {
    printf("Instrucao goto_wFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::jsr_wFunction(Frame* frame) {
    printf("Instrucao jsr_wFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}