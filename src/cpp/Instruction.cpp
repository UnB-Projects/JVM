#include "../hpp/Instruction.hpp"

Instruction::Instruction() {
    //Para declarar sem argumentos
}


Instruction::Instruction(string mnemonic, uint32_t bytesCount, void (*func)(Frame*)) {
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

void Instruction::nopFunction(Frame*) {
    printf("Instrucao nopFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::aconst_nullFunction(Frame*) {
    printf("Instrucao aconst_nullFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_m1Function(Frame*) {
    printf("Instrucao iconst_m1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_0Function(Frame*) {
    printf("Instrucao iconst_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_1Function(Frame*) {
    printf("Instrucao iconst_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_2Function(Frame*) {
    printf("Instrucao iconst_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_3Function(Frame*) {
    printf("Instrucao iconst_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_4Function(Frame*) {
    printf("Instrucao iconst_4Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iconst_5Function(Frame*) {
    printf("Instrucao iconst_5Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lconst_0Function(Frame*) {
    printf("Instrucao lconst_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lconst_1Function(Frame*) {
    printf("Instrucao lconst_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fconst_0Function(Frame*) {
    printf("Instrucao fconst_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fconst_1Function(Frame*) {
    printf("Instrucao fconst_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fconst_2Function(Frame*) {
    printf("Instrucao fconst_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dconst_0Function(Frame*) {
    printf("Instrucao dconst_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dconst_1Function(Frame*) {
    printf("Instrucao dconst_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::bipushFunction(Frame*) {
    printf("Instrucao bipushFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::sipushFunction(Frame*) {
    printf("Instrucao sipushFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ldcFunction(Frame*) {
    printf("Instrucao ldcFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ldc_wFunction(Frame*) {
    printf("Instrucao ldc_wFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ldc2_wFunction(Frame*) {
    printf("Instrucao ldc2_wFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iloadFunction(Frame*) {
    printf("Instrucao iloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lloadFunction(Frame*) {
    printf("Instrucao lloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::floadFunction(Frame*) {
    printf("Instrucao floadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dloadFunction(Frame*) {
    printf("Instrucao dloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::aloadFunction(Frame*) {
    printf("Instrucao aloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iload_0Function(Frame*) {
    printf("Instrucao iload_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iload_1Function(Frame*) {
    printf("Instrucao iload_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iload_2Function(Frame*) {
    printf("Instrucao iload_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iload_3Function(Frame*) {
    printf("Instrucao iload_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lload_0Function(Frame*) {
    printf("Instrucao lload_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lload_1Function(Frame*) {
    printf("Instrucao lload_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lload_2Function(Frame*) {
    printf("Instrucao lload_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lload_3Function(Frame*) {
    printf("Instrucao lload_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fload_0Function(Frame*) {
    printf("Instrucao fload_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fload_1Function(Frame*) {
    printf("Instrucao fload_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fload_2Function(Frame*) {
    printf("Instrucao fload_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fload_3Function(Frame*) {
    printf("Instrucao fload_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dload_0Function(Frame*) {
    printf("Instrucao dload_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dload_1Function(Frame*) {
    printf("Instrucao dload_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dload_2Function(Frame*) {
    printf("Instrucao dload_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dload_3Function(Frame*) {
    printf("Instrucao dload_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::aload_0Function(Frame*) {
    printf("Instrucao aload_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::aload_1Function(Frame*) {
    printf("Instrucao aload_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::aload_2Function(Frame*) {
    printf("Instrucao aload_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::aload_3Function(Frame*) {
    printf("Instrucao aload_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::ialoadFunction(Frame*) {
    printf("Instrucao ialoadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::laloadFunction(Frame*) {
    printf("Instrucao laloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::faloadFunction(Frame*) {
    printf("Instrucao faloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::daloadFunction(Frame*) {
    printf("Instrucao daloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::aaloadFunction(Frame*) {
    printf("Instrucao aaloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::baloadFunction(Frame*) {
    printf("Instrucao baloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::caloadFunction(Frame*) {
    printf("Instrucao caloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::saloadFunction(Frame*) {
    printf("Instrucao saloadFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::istoreFunction(Frame*) {
    printf("Instrucao istoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lstoreFunction(Frame*) {
    printf("Instrucao lstoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fstoreFunction(Frame*) {
    printf("Instrucao fstoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dstoreFunction(Frame*) {
    printf("Instrucao dstoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::astoreFunction(Frame*) {
    printf("Instrucao astoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::istore_0Function(Frame*) {
    printf("Instrucao istore_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::istore_1Function(Frame*) {
    printf("Instrucao istore_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::istore_2Function(Frame*) {
    printf("Instrucao istore_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::istore_3Function(Frame*) {
    printf("Instrucao istore_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lstore_0Function(Frame*) {
    printf("Instrucao lstore_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lstore_1Function(Frame*) {
    printf("Instrucao lstore_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lstore_2Function(Frame*) {
    printf("Instrucao lstore_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::lstore_3Function(Frame*) {
    printf("Instrucao lstore_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fstore_0Function(Frame*) {
    printf("Instrucao fstore_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fstore_1Function(Frame*) {
    printf("Instrucao fstore_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fstore_2Function(Frame*) {
    printf("Instrucao fstore_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::fstore_3Function(Frame*) {
    printf("Instrucao fstore_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dstore_0Function(Frame*) {
    printf("Instrucao dstore_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dstore_1Function(Frame*) {
    printf("Instrucao dstore_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dstore_2Function(Frame*) {
    printf("Instrucao dstore_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dstore_3Function(Frame*) {
    printf("Instrucao dstore_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::astore_0Function(Frame*) {
    printf("Instrucao astore_0Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::astore_1Function(Frame*) {
    printf("Instrucao astore_1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::astore_2Function(Frame*) {
    printf("Instrucao astore_2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::astore_3Function(Frame*) {
    printf("Instrucao astore_3Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::iastoreFunction(Frame*) {
    printf("Instrucao iastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lastoreFunction(Frame*) {
    printf("Instrucao lastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fastoreFunction(Frame*) {
    printf("Instrucao fastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dastoreFunction(Frame*) {
    printf("Instrucao dastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::aastoreFunction(Frame*) {
    printf("Instrucao aastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::bastoreFunction(Frame*) {
    printf("Instrucao bastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::castoreFunction(Frame*) {
    printf("Instrucao castoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::sastoreFunction(Frame*) {
    printf("Instrucao sastoreFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::popFunction(Frame*) {
    printf("Instrucao popFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::pop2Function(Frame*) {
    printf("Instrucao pop2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dupFunction(Frame*) {
    printf("Instrucao dupFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dup_x1Function(Frame*) {
    printf("Instrucao dup_x1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dup_x2Function(Frame*) {
    printf("Instrucao dup_x2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dup2Function(Frame*) {
    printf("Instrucao dup2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dup2_x1Function(Frame*) {
    printf("Instrucao dup2_x1Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::dup2_x2Function(Frame*) {
    printf("Instrucao dup2_x2Function nao implementada ainda!\n");
    exit(0);
}
void Instruction::swapFunction(Frame*) {
    printf("Instrucao swapFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iaddFunction(Frame*) {
    printf("Instrucao iaddFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::laddFunction(Frame*) {
    printf("Instrucao laddFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::faddFunction(Frame*) {
    printf("Instrucao faddFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::daddFunction(Frame*) {
    printf("Instrucao daddFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::isubFunction(Frame*) {
    printf("Instrucao isubFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lsubFunction(Frame*) {
    printf("Instrucao lsubFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fsubFunction(Frame*) {
    printf("Instrucao fsubFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dsubFunction(Frame*) {
    printf("Instrucao dsubFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::imulFunction(Frame*) {
    printf("Instrucao imulFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lmulFunction(Frame*) {
    printf("Instrucao lmulFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fmulFunction(Frame*) {
    printf("Instrucao fmulFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dmulFunction(Frame*) {
    printf("Instrucao dmulFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::idivFunction(Frame*) {
    printf("Instrucao idivFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ldivOpFunction(Frame*) {
    printf("Instrucao ldivOpFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fdivFunction(Frame*) {
    printf("Instrucao fdivFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ddivFunction(Frame*) {
    printf("Instrucao ddivFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iremFunction(Frame*) {
    printf("Instrucao iremFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lremFunction(Frame*) {
    printf("Instrucao lremFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fremFunction(Frame*) {
    printf("Instrucao fremFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dremFunction(Frame*) {
    printf("Instrucao dremFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::inegFunction(Frame*) {
    printf("Instrucao inegFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lnegFunction(Frame*) {
    printf("Instrucao lnegFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fnegFunction(Frame*) {
    printf("Instrucao fnegFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dnegFunction(Frame*) {
    printf("Instrucao dnegFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ishlFunction(Frame*) {
    printf("Instrucao ishlFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lshlFunction(Frame*) {
    printf("Instrucao lshlFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ishrFunction(Frame*) {
    printf("Instrucao ishrFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lshrFunction(Frame*) {
    printf("Instrucao lshrFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iushrFunction(Frame*) {
    printf("Instrucao iushrFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lushrFunction(Frame*) {
    printf("Instrucao lushrFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iandFunction(Frame*) {
    printf("Instrucao iandFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::landFunction(Frame*) {
    printf("Instrucao landFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iorFunction(Frame*) {
    printf("Instrucao iorFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lorFunction(Frame*) {
    printf("Instrucao lorFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ixorFunction(Frame*) {
    printf("Instrucao ixorFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lxorFunction(Frame*) {
    printf("Instrucao lxorFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::iincFunction(Frame*) {
    printf("Instrucao iincFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::i2lFunction(Frame*) {
    printf("Instrucao i2lFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::i2fFunction(Frame*) {
    printf("Instrucao i2fFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::i2dFunction(Frame*) {
    printf("Instrucao i2dFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::l2iFunction(Frame*) {
    printf("Instrucao l2iFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::l2fFunction(Frame*) {
    printf("Instrucao l2fFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::l2dFunction(Frame*) {
    printf("Instrucao l2dFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::f2iFunction(Frame*) {
    printf("Instrucao f2iFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::f2lFunction(Frame*) {
    printf("Instrucao f2lFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::f2dFunction(Frame*) {
    printf("Instrucao f2dFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::d2iFunction(Frame*) {
    printf("Instrucao d2iFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::d2lFunction(Frame*) {
    printf("Instrucao d2lFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::d2fFunction(Frame*) {
    printf("Instrucao d2fFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::i2bFunction(Frame*) {
    printf("Instrucao i2bFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::i2cFunction(Frame*) {
    printf("Instrucao i2cFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::i2sFunction(Frame*) {
    printf("Instrucao i2sFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lcmpFunction(Frame*) {
    printf("Instrucao lcmpFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fcmplFunction(Frame*) {
    printf("Instrucao fcmplFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::fcmpgFunction(Frame*) {
    printf("Instrucao fcmpgFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dcmplFunction(Frame*) {
    printf("Instrucao dcmplFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dcmpgFunction(Frame*) {
    printf("Instrucao dcmpgFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifeqFunction(Frame*) {
    printf("Instrucao ifeqFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifneFunction(Frame*) {
    printf("Instrucao ifneFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifltFunction(Frame*) {
    printf("Instrucao ifltFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifgeFunction(Frame*) {
    printf("Instrucao ifgeFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifgtFunction(Frame*) {
    printf("Instrucao ifgtFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifleFunction(Frame*) {
    printf("Instrucao ifleFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_icmpeqFunction(Frame*) {
    printf("Instrucao if_icmpeqFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_icmpneFunction(Frame*) {
    printf("Instrucao if_icmpneFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_icmpltFunction(Frame*) {
    printf("Instrucao if_icmpltFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_icmpgeFunction(Frame*) {
    printf("Instrucao if_icmpgeFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_icmpgtFunction(Frame*) {
    printf("Instrucao if_icmpgtFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_icmpleFunction(Frame*) {
    printf("Instrucao if_icmpleFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_acmpeqFunction(Frame*) {
    printf("Instrucao if_acmpeqFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::if_acmpneFunction(Frame*) {
    printf("Instrucao if_acmpneFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::gotoOpFunction(Frame*) {
    printf("Instrucao gotoOpFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::jsrFunction(Frame*) {
    printf("Instrucao jsrFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::retFunction(Frame*) {
    printf("Instrucao retFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::tableswitchFunction(Frame*) {
    printf("Instrucao tableswitchFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lookupswitchFunction(Frame*) {
    printf("Instrucao lookupswitchFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ireturnFunction(Frame*) {
    printf("Instrucao ireturnFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::lreturnFunction(Frame*) {
    printf("Instrucao lreturnFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::freturnFunction(Frame*) {
    printf("Instrucao freturnFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::dreturnFunction(Frame*) {
    printf("Instrucao dreturnFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::areturnFunction(Frame*) {
    printf("Instrucao areturnFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::returnOpFunction(Frame*) {
    printf("Instrucao returnOpFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::getstaticFunction(Frame*) {

}
void Instruction::putstaticFunction(Frame*) {
    printf("Instrucao putstaticFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::getfieldFunction(Frame*) {
    printf("Instrucao getfieldFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::putfieldFunction(Frame*) {
    printf("Instrucao putfieldFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::invokevirtualFunction(Frame*) {
    printf("Instrucao invokevirtualFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::invokespecialFunction(Frame*) {
    printf("Instrucao invokespecialFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::invokestaticFunction(Frame*) {
    printf("Instrucao invokestaticFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::invokeinterfaceFunction(Frame*) {
    printf("Instrucao invokeinterfaceFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::invokedynamicFunction(Frame*) {
    printf("Instrucao invokedynamicFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::newOpFunction(Frame*) {
    printf("Instrucao newOpFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::newarrayFunction(Frame*) {
    printf("Instrucao newarrayFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::anewarrayFunction(Frame*) {
    printf("Instrucao anewarrayFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::arraylengthFunction(Frame*) {
    printf("Instrucao arraylengthFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::athrowFunction(Frame*) {
    printf("Instrucao athrowFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::checkcastFunction(Frame*) {
    printf("Instrucao checkcastFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::instanceofFunction(Frame*) {
    printf("Instrucao instanceofFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::monitorenterFunction(Frame*) {
    printf("Instrucao monitorenterFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::monitorexitFunction(Frame*) {
    printf("Instrucao monitorexitFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::wideFunction(Frame*) {
    printf("Instrucao wideFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::multianewarrayFunction(Frame*) {
    printf("Instrucao multianewarrayFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifnullFunction(Frame*) {
    printf("Instrucao ifnullFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::ifnonnullFunction(Frame*) {
    printf("Instrucao ifnonnullFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::goto_wFunction(Frame*) {
    printf("Instrucao goto_wFunction nao implementada ainda!\n");
    exit(0);
}
void Instruction::jsr_wFunction(Frame*) {
    printf("Instrucao jsr_wFunction nao implementada ainda!\n");
    exit(0);
}