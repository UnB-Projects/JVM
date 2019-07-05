#include "../hpp/Instruction.hpp"

void Instruction::setClassLoader(ClassLoader* classLoader) {
    Instruction::classLoader = classLoader;
}

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
    return ++frame->localPC;
}
uint32_t Instruction::aconst_nullFunction(Frame* frame) {
    JavaType null;
    null.tag = CAT_NULL;
    null.type_reference = JAVA_NULL;
    frame->operandStack.push(null);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_m1Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)(-1);
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_0Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)0;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_1Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)1;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_2Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)2;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_3Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)3;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_4Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)4;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::iconst_5Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT1;
    constant.type_int = (int32_t)5;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::lconst_0Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT2;
    constant.type_long = (int64_t)0;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::lconst_1Function(Frame* frame) {
    JavaType constant;
    constant.tag = CAT2;
    constant.type_long = (int64_t)1;
    frame->operandStack.push(constant);
    return ++frame->localPC;
}
uint32_t Instruction::fconst_0Function(Frame* frame) {
    JavaType value;
    float fconst = 0.0f;

    memcpy(&value.type_float, &fconst, sizeof(uint32_t));
    value.tag = CAT1;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::fconst_1Function(Frame* frame) {
    JavaType value;
    float fconst = 1.0f;

    memcpy(&value.type_float, &fconst, sizeof(uint32_t));
    value.tag = CAT1;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::fconst_2Function(Frame* frame) {
    JavaType value;
    float fconst = 2.0f;

    memcpy(&value.type_float, &fconst, sizeof(uint32_t));
    value.tag = CAT1;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::dconst_0Function(Frame* frame) {
    JavaType value;
    double dconst = 0.0;

    memcpy(&value.type_double, &dconst, sizeof(uint64_t));
    value.tag = CAT2;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::dconst_1Function(Frame* frame) {
    JavaType value;
    double dconst = 1.0;

    memcpy(&value.type_double, &dconst, sizeof(uint64_t));
    value.tag = CAT2;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::bipushFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte = bytecode[++frame->localPC];
    JavaType value;

    value.type_int = (int32_t)((int8_t)byte);
    value.tag = CAT1;
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::sipushFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    JavaType value;

    value.type_short = (int32_t)(((uint16_t)byte1 << 8) | byte2);
    value.tag = CAT1;
    frame->operandStack.push(value);

    return ++frame->localPC;
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
        value.type_reference = (uint64_t)new string(cpInfo->getInfo(frame->constantPool).second);
        value.tag = CAT1;
        frame->operandStack.push(value);
        break;
    case CPInfo::CONSTANT_Integer:
        value.type_int = cpInfo->getIntegerInfo().bytes;
        value.tag = CAT1;
        frame->operandStack.push(value);
        break;
    case CPInfo::CONSTANT_Float:
        value.type_float = cpInfo->getFloatInfo().bytes;
        value.tag = CAT1;
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
        value.tag = CAT2;
        frame->operandStack.push(value);
        break;
    case CPInfo::CONSTANT_Double:
        value.type_double = ((uint64_t)cpInfo->getDoubleInfo().high_bytes << 32) | cpInfo->getDoubleInfo().low_bytes;
        value.tag = CAT2;
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
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value = frame->localVariables[index];
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::lloadFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value = frame->localVariables[index];
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::floadFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value = frame->localVariables[index];
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::dloadFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value = frame->localVariables[index];
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::aloadFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value = frame->localVariables[index];
    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::iload_0Function(Frame* frame) {
    JavaType value;
    value.type_int = frame->localVariables[0].type_int;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::iload_1Function(Frame* frame) {
    JavaType value;
    value.type_int = frame->localVariables[1].type_int;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::iload_2Function(Frame* frame) {
    JavaType value;
    value.type_int = frame->localVariables[2].type_int;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::iload_3Function(Frame* frame) {
    JavaType value;
    value.type_int = frame->localVariables[3].type_int;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::lload_0Function(Frame* frame) {
    JavaType value;
    value.type_long = frame->localVariables[0].type_long;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::lload_1Function(Frame* frame) {
    JavaType value;
    value.type_long = frame->localVariables[1].type_long;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::lload_2Function(Frame* frame) {
    JavaType value;
    value.type_long = frame->localVariables[2].type_long;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::lload_3Function(Frame* frame) {
    JavaType value;
    value.type_long = frame->localVariables[3].type_long;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::fload_0Function(Frame* frame) {
    JavaType value;
    value.type_float = frame->localVariables[0].type_float;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::fload_1Function(Frame* frame) {
    JavaType value;
    value.type_float = frame->localVariables[1].type_float;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::fload_2Function(Frame* frame) {
    JavaType value;
    value.type_float = frame->localVariables[2].type_float;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::fload_3Function(Frame* frame) {
    JavaType value;
    value.type_float = frame->localVariables[3].type_float;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::dload_0Function(Frame* frame) {
    JavaType value;
    value.type_double = frame->localVariables[0].type_double;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::dload_1Function(Frame* frame) {
    JavaType value;
    value.type_double = frame->localVariables[1].type_double;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::dload_2Function(Frame* frame) {
    JavaType value;
    value.type_double = frame->localVariables[2].type_double;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::dload_3Function(Frame* frame) {
    JavaType value;
    value.type_double = frame->localVariables[3].type_double;
    frame->operandStack.push(value);
    return ++frame->localPC;
}
uint32_t Instruction::aload_0Function(Frame* frame) {
    JavaType objectref;

    objectref.type_reference = frame->localVariables[0].type_reference;
    frame->operandStack.push(objectref);

    return ++frame->localPC;
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
    JavaType objectref;

    objectref.type_reference = frame->localVariables[3].type_reference;
    frame->operandStack.push(objectref);

    return ++frame->localPC;
}
uint32_t Instruction::ialoadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::laloadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::faloadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::daloadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::aaloadFunction(Frame* frame) {
    printf("Instrucao aaloadFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::baloadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::caloadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::saloadFunction(Frame* frame) {
    JavaType index;
    JavaType arrayref;

    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    JavaType value = array->at((int32_t)index.type_int);

    frame->operandStack.push(value);

    return ++frame->localPC;
}
uint32_t Instruction::istoreFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value.tag = CAT1;
    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    frame->localVariables[index] = value;

    return ++frame->localPC;
}
uint32_t Instruction::lstoreFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value.tag = CAT2;
    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    frame->localVariables[index] = value;

    return ++frame->localPC;
}
uint32_t Instruction::fstoreFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value.tag = CAT1;
    value.type_float = frame->operandStack.top().type_float;
    frame->operandStack.pop();
    frame->localVariables[index] = value;

    return ++frame->localPC;
}
uint32_t Instruction::dstoreFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value.tag = CAT2;
    value.type_double = frame->operandStack.top().type_double;
    frame->operandStack.pop();
    frame->localVariables[index] = value;

    return ++frame->localPC;
}
uint32_t Instruction::astoreFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t index = bytecode[++frame->localPC];
    JavaType value;

    value.tag = CAT1;
    value.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[index] = value;

    return ++frame->localPC;
}
uint32_t Instruction::istore_0Function(Frame* frame) {
    frame->localVariables[0] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::istore_1Function(Frame* frame) {
    frame->localVariables[1] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::istore_2Function(Frame* frame) {
    frame->localVariables[2] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::istore_3Function(Frame* frame) {
    frame->localVariables[3] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::lstore_0Function(Frame* frame) {
    frame->localVariables[0] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::lstore_1Function(Frame* frame) {
    frame->localVariables[1] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::lstore_2Function(Frame* frame) {
    frame->localVariables[2] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::lstore_3Function(Frame* frame) {
    frame->localVariables[3] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::fstore_0Function(Frame* frame) {
    frame->localVariables[0] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::fstore_1Function(Frame* frame) {
    frame->localVariables[1] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::fstore_2Function(Frame* frame) {
    frame->localVariables[2] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::fstore_3Function(Frame* frame) {
    frame->localVariables[3] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::dstore_0Function(Frame* frame) {
    frame->localVariables[0] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::dstore_1Function(Frame* frame) {
    frame->localVariables[1] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::dstore_2Function(Frame* frame) {
    frame->localVariables[2] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::dstore_3Function(Frame* frame) {
    frame->localVariables[3] = frame->operandStack.top();
    frame->operandStack.pop();
    return ++frame->localPC;
}
uint32_t Instruction::astore_0Function(Frame* frame) {
    JavaType objectref;

    objectref.tag = CAT1;
    objectref.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[0] = objectref;

    return ++frame->localPC;
}
uint32_t Instruction::astore_1Function(Frame* frame) {
    JavaType objectref;

    objectref.tag = CAT1;
    objectref.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[1] = objectref;

    return ++frame->localPC;
}
uint32_t Instruction::astore_2Function(Frame* frame) {
    JavaType objectref;

    objectref.tag = CAT1;
    objectref.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[2] = objectref;

    return ++frame->localPC;
}
uint32_t Instruction::astore_3Function(Frame* frame) {
    JavaType objectref;

    objectref.tag = CAT1;
    objectref.type_reference = frame->operandStack.top().type_reference;
    frame->operandStack.pop();
    frame->localVariables[3] = objectref;

    return ++frame->localPC;
}
uint32_t Instruction::iastoreFunction(Frame* frame) {
    JavaType value;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = value;

    return ++frame->localPC;
}
uint32_t Instruction::lastoreFunction(Frame* frame) {
    JavaType value;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = value;

    return ++frame->localPC;
}
uint32_t Instruction::fastoreFunction(Frame* frame) {
    JavaType value;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = value;

    return ++frame->localPC;
}
uint32_t Instruction::dastoreFunction(Frame* frame) {
    JavaType value;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = value;

    return ++frame->localPC;
}
uint32_t Instruction::aastoreFunction(Frame* frame) {
    printf("Instrucao aastoreFunction nao implementada ainda!\n");
    exit(0);
    return -1;
}
uint32_t Instruction::bastoreFunction(Frame* frame) {
    JavaType value;
    JavaType byteValue;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    byteValue.tag = CAT1;
    byteValue.type_byte = (int8_t)value.type_int;

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = byteValue;

    return ++frame->localPC;
}
uint32_t Instruction::castoreFunction(Frame* frame) {
    JavaType value;
    JavaType charValue;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    charValue.tag = CAT1;
    charValue.type_byte = (int8_t)value.type_int;

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = charValue;

    return ++frame->localPC;
}
uint32_t Instruction::sastoreFunction(Frame* frame) {
    JavaType value;
    JavaType shortValue;
    JavaType index;
    JavaType arrayref;

    value = frame->operandStack.top();
    frame->operandStack.pop();
    index = frame->operandStack.top();
    frame->operandStack.pop();
    arrayref = frame->operandStack.top();
    frame->operandStack.pop();

    shortValue.tag = CAT1;
    shortValue.type_byte = (int16_t)value.type_int;

    vector<JavaType>* array = (vector<JavaType>*)arrayref.type_reference;
    array->at((int32_t)index.type_int) = shortValue;

    return ++frame->localPC;
}
uint32_t Instruction::popFunction(Frame* frame) {
    frame->operandStack.pop();
    return ++frame->localPC;
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
    if (frame->operandStack.top().tag == CAT1) {
        JavaType value1 = frame->operandStack.top();
        frame->operandStack.pop();
        JavaType value2 = frame->operandStack.top();
        frame->operandStack.pop();

        frame->operandStack.push(value2);
        frame->operandStack.push(value1);
        frame->operandStack.push(value2);
        frame->operandStack.push(value1);
    }
    else if(frame->operandStack.top().tag == CAT2) {
        JavaType value = frame->operandStack.top();
        frame->operandStack.pop();
        frame->operandStack.push(value);
        frame->operandStack.push(value);
    }
    else {
        cout << "Erro no dup2: categoria indefinida!: " << frame->operandStack.top().tag << endl;
    }
    return ++frame->localPC;
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
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_int = (int32_t)value1.type_int + (int32_t)value2.type_int;

    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::laddFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long + (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::faddFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;
    float fresult;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    fresult = fvalue1 + fvalue2;

    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::daddFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;
    double dresult;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    dresult = dvalue1 + dvalue2;

    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::isubFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)((int32_t)value1.type_int - (int32_t)value2.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lsubFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long - (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::fsubFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;
    float fresult;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    fresult = fvalue1 - fvalue2;

    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::dsubFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;
    double dresult;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    dresult = dvalue1 - dvalue2;

    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::imulFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)((int32_t)value1.type_int * (int32_t)value2.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lmulFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long * (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::fmulFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;
    float fresult;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    fresult = fvalue1 * fvalue2;

    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::dmulFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;
    double dresult;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    dresult = dvalue1 * dvalue2;

    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::idivFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)((int32_t)value1.type_int / (int32_t)value2.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::ldivOpFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long / (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::fdivFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;
    float fresult;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    fresult = fvalue1 / fvalue2;

    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::ddivFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;
    double dresult;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    dresult = dvalue1 / dvalue2;

    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::iremFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)((int32_t)value1.type_int - (int32_t)((int32_t)value1.type_int / (int32_t)value2.type_int) * (int32_t)value2.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lremFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    result.type_long = (int64_t)((int64_t)value1.type_long - (int64_t)((int64_t)value1.type_long / (int64_t)value2.type_long) * (int64_t)value2.type_long);
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::fremFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;
    float fresult;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    fresult = fmod(fvalue1, fvalue2);

    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::dremFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;
    double dresult;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    dresult = fmod(dvalue1, dvalue2);

    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::inegFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)(-(int32_t)value.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lnegFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    result.type_long = (int64_t)(-(int64_t)value.type_long);
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::fnegFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    float fvalue;
    float fresult;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    memcpy(&fvalue, &value.type_int, sizeof(float));

    fresult = -fvalue;

    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::dnegFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    double dvalue;
    double dresult;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    memcpy(&dvalue, &value.type_long, sizeof(double));

    dresult = -dvalue;

    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::ishlFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)((int32_t)value1.type_int << ((int32_t)value2.type_int & 0x0000001F));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lshlFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    result.type_long = (int64_t)((int64_t)value1.type_long << ((int32_t)value2.type_int & 0x0000003F));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::ishrFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (int32_t)((int32_t)value1.type_int >> ((int32_t)value2.type_int & 0x0000001F));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lshrFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    result.type_long = (int64_t)((int64_t)value1.type_long >> ((int32_t)value2.type_int & 0x0000003F));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::iushrFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    result.type_int = (uint32_t)((uint32_t)value1.type_int >> ((int32_t)value2.type_int & 0x0000001F));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lushrFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    result.type_long = (uint64_t)((uint64_t)value1.type_long >> ((int32_t)value2.type_int & 0x0000003F));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::iandFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_int = (int32_t)value1.type_int & (int32_t)value2.type_int;
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::landFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long & (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::iorFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_int = (int32_t)value1.type_int | (int32_t)value2.type_int;
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lorFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long | (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::ixorFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_int = (int32_t)value1.type_int ^ (int32_t)value2.type_int;
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::lxorFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_long = (int64_t)value1.type_long ^ (int64_t)value2.type_long;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::iincFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];

    uint16_t index = byte1;
    int32_t constValue = (int32_t)((int8_t)byte2);
    frame->localVariables[index].type_int = (int32_t)frame->localVariables[index].type_int + constValue;

    return ++frame->localPC;
}
uint32_t Instruction::i2lFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_long = (int64_t)((int32_t)value.type_int);
    result.tag = CAT2;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::i2fFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    float fresult;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    fresult = (float)((int32_t)value.type_int);
    memcpy(&(result.type_float), &fresult, sizeof(float));

    result.tag = CAT1;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::i2dFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    double dresult;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    dresult = (double)((int32_t)value.type_int);
    memcpy(&(result.type_float), &dresult, sizeof(double));

    result.tag = CAT2;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::l2iFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    result.type_int = int32_t((int64_t)value.type_long);
    result.tag = CAT1;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::l2fFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    float fresult;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    fresult = (float)((int64_t)value.type_long);
    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::l2dFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    double dresult;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    dresult = (double)((int64_t)value.type_long);
    memcpy(&(result.type_float), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::f2iFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    float fvalue;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue, &(value.type_int), sizeof(float));
    result.type_int = (int32_t)fvalue;
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::f2lFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    float fvalue;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue, &(value.type_int), sizeof(float));
    result.type_long = (int64_t)fvalue;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::f2dFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    float fvalue;
    double dresult;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue, &(value.type_int), sizeof(float));
    dresult = (double)fvalue;
    memcpy(&(result.type_double), &dresult, sizeof(double));
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::d2iFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    double dvalue;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue, &(value.type_long), sizeof(double));
    result.type_int = (int32_t)dvalue;
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::d2lFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    double dvalue;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue, &(value.type_long), sizeof(double));
    result.type_long = (int64_t)dvalue;
    result.tag = CAT2;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::d2fFunction(Frame* frame) {
    JavaType value;
    JavaType result;
    double dvalue;
    float fresult;

    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue, &(value.type_long), sizeof(double));
    fresult = (float)dvalue;
    memcpy(&(result.type_float), &fresult, sizeof(float));
    result.tag = CAT1;
    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::i2bFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_byte = (int8_t)((int32_t)value.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::i2cFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_char = (uint8_t)((int32_t)value.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::i2sFunction(Frame* frame) {
    JavaType value;
    JavaType result;

    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    result.type_short = (int16_t)((int32_t)value.type_int);
    result.tag = CAT1;
    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::lcmpFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    if (value1.type_long > value2.type_long) {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }
    else if (value1.type_long == value2.type_long) {
        result.tag = CAT1;
        result.type_int = (int32_t)0;
    }
    else if (value1.type_long < value2.type_long) {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }

    frame->operandStack.push(result);

    return ++frame->localPC;
}
uint32_t Instruction::fcmplFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    if (fvalue1 > fvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }
    else if (fvalue1 == fvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)0;
    }
    else if (fvalue1 < fvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }
    else {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }

    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::fcmpgFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    float fvalue1;
    float fvalue2;

    value2.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    value1.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();

    memcpy(&fvalue1, &value1.type_int, sizeof(float));
    memcpy(&fvalue2, &value2.type_int, sizeof(float));

    if (fvalue1 > fvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }
    else if (fvalue1 == fvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)0;
    }
    else if (fvalue1 < fvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }
    else {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }

    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::dcmplFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    if (dvalue1 > dvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }
    else if (dvalue1 == dvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)0;
    }
    else if (dvalue1 < dvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }
    else {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }

    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::dcmpgFunction(Frame* frame) {
    JavaType value1;
    JavaType value2;
    JavaType result;
    double dvalue1;
    double dvalue2;

    value2.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    value1.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();

    memcpy(&dvalue1, &value1.type_long, sizeof(double));
    memcpy(&dvalue2, &value2.type_long, sizeof(double));

    if (dvalue1 > dvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }
    else if (dvalue1 == dvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)0;
    }
    else if (dvalue1 < dvalue2) {
        result.tag = CAT1;
        result.type_int = (int32_t)-1;
    }
    else {
        result.tag = CAT1;
        result.type_int = (int32_t)1;
    }

    frame->operandStack.push(result);
    return ++frame->localPC;
}
uint32_t Instruction::ifeqFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value.type_int == 0) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::ifneFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value.type_int != 0) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::ifltFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value.type_int < 0) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::ifgeFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value.type_int >= 0) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::ifgtFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value.type_int > 0) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::ifleFunction(Frame* frame) {
uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value.type_int <= 0) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::if_icmpeqFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value2 = frame->operandStack.top();
    frame->operandStack.pop();
    JavaType value1 = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value1.type_int == (int32_t)value2.type_int) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::if_icmpneFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value2 = frame->operandStack.top();
    frame->operandStack.pop();
    JavaType value1 = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value1.type_int != (int32_t)value2.type_int) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::if_icmpltFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value2 = frame->operandStack.top();
    frame->operandStack.pop();
    JavaType value1 = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value1.type_int < (int32_t)value2.type_int) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::if_icmpgeFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value2 = frame->operandStack.top();
    frame->operandStack.pop();
    JavaType value1 = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value1.type_int >= (int32_t)value2.type_int) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::if_icmpgtFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value2 = frame->operandStack.top();
    frame->operandStack.pop();
    JavaType value1 = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value1.type_int > (int32_t)value2.type_int) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::if_icmpleFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value2 = frame->operandStack.top();
    frame->operandStack.pop();
    JavaType value1 = frame->operandStack.top();
    frame->operandStack.pop();

    if ((int32_t)value1.type_int <= (int32_t)value2.type_int) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
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
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    frame->localPC = baseAddress + branchOffset;
    return frame->localPC;
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
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    JavaType key = frame->operandStack.top();
    frame->operandStack.pop();

    while ((frame->localPC)%4 != 0) {
        frame->localPC++;
    }

    uint8_t defaultByte1 = bytecode[frame->localPC++];
    uint8_t defaultByte2 = bytecode[frame->localPC++];
    uint8_t defaultByte3 = bytecode[frame->localPC++];
    uint8_t defaultByte4 = bytecode[frame->localPC++];
    int32_t defaultValue = (defaultByte1 << 24) | (defaultByte2 << 16) | (defaultByte3 << 8) | defaultByte4;

    uint8_t lowByte1 = bytecode[frame->localPC++];
    uint8_t lowByte2 = bytecode[frame->localPC++];
    uint8_t lowByte3 = bytecode[frame->localPC++];
    uint8_t lowByte4 = bytecode[frame->localPC++];
    int32_t low = (lowByte1 << 24) | (lowByte2 << 16) | (lowByte3 << 8) | lowByte4;

    uint8_t highByte1 = bytecode[frame->localPC++];
    uint8_t highByte2 = bytecode[frame->localPC++];
    uint8_t highByte3 = bytecode[frame->localPC++];
    uint8_t highByte4 = bytecode[frame->localPC++];
    int32_t high = (highByte1 << 24) | (highByte2 << 16) | (highByte3 << 8) | highByte4;

    for (int match = low; match <= high; match++) {
        uint8_t offsetByte1 = bytecode[frame->localPC++];
        uint8_t offsetByte2 = bytecode[frame->localPC++];
        uint8_t offsetByte3 = bytecode[frame->localPC++];
        uint8_t offsetByte4 = bytecode[frame->localPC++];
        int32_t offset = (offsetByte1 << 24) | (offsetByte2 << 16) | (offsetByte3 << 8) | offsetByte4;

        if ((int32_t)key.type_int == match) {
            frame->localPC = baseAddress + offset;
            return frame->localPC;
        }
    }
    frame->localPC = baseAddress + defaultValue;
    return frame->localPC;
}
uint32_t Instruction::lookupswitchFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    JavaType key = frame->operandStack.top();
    frame->operandStack.pop();

    while ((frame->localPC)%4 != 0) {
        frame->localPC++;
    }

    uint8_t defaultByte1 = bytecode[frame->localPC++];
    uint8_t defaultByte2 = bytecode[frame->localPC++];
    uint8_t defaultByte3 = bytecode[frame->localPC++];
    uint8_t defaultByte4 = bytecode[frame->localPC++];
    int32_t defaultValue = (defaultByte1 << 24) | (defaultByte2 << 16) | (defaultByte3 << 8) | defaultByte4;

    uint8_t npairs1 = bytecode[frame->localPC++];
    uint8_t npairs2 = bytecode[frame->localPC++];
    uint8_t npairs3 = bytecode[frame->localPC++];
    uint8_t npairs4 = bytecode[frame->localPC++];
    int32_t npairs = (npairs1 << 24) | (npairs2 << 16) | (npairs3 << 8) | npairs4;

    for (int i = 0; i < npairs; i++) {
        uint8_t matchByte1 = bytecode[frame->localPC++];
        uint8_t matchByte2 = bytecode[frame->localPC++];
        uint8_t matchByte3 = bytecode[frame->localPC++];
        uint8_t matchByte4 = bytecode[frame->localPC++];
        int32_t match = (matchByte1 << 24) | (matchByte2 << 16) | (matchByte3 << 8) | matchByte4;

        uint8_t offsetByte1 = bytecode[frame->localPC++];
        uint8_t offsetByte2 = bytecode[frame->localPC++];
        uint8_t offsetByte3 = bytecode[frame->localPC++];
        uint8_t offsetByte4 = bytecode[frame->localPC++];
        int32_t offset = (offsetByte1 << 24) | (offsetByte2 << 16) | (offsetByte3 << 8) | offsetByte4;

        if ((int32_t)key.type_int == match) {
            frame->localPC = baseAddress + offset;
            return frame->localPC;
        }
    }
    frame->localPC = baseAddress + defaultValue;
    return frame->localPC;
}
uint32_t Instruction::ireturnFunction(Frame* frame) {
    JavaType value;

    value.tag = CAT1;
    value.type_int = frame->operandStack.top().type_int;
    frame->operandStack.pop();
    frame->jvmStack->pop();

    Frame* invoker = &(frame->jvmStack->top());
    invoker->operandStack.push(value);
    return invoker->localPC;
}
uint32_t Instruction::lreturnFunction(Frame* frame) {
    JavaType value;

    value.tag = CAT2;
    value.type_long = frame->operandStack.top().type_long;
    frame->operandStack.pop();
    frame->jvmStack->pop();

    Frame* invoker = &(frame->jvmStack->top());
    invoker->operandStack.push(value);
    return invoker->localPC;
}
uint32_t Instruction::freturnFunction(Frame* frame) {
    JavaType value;

    value.tag = CAT1;
    value.type_float = frame->operandStack.top().type_float;
    frame->operandStack.pop();
    frame->jvmStack->pop();

    Frame* invoker = &(frame->jvmStack->top());
    invoker->operandStack.push(value);
    return invoker->localPC;
}
uint32_t Instruction::dreturnFunction(Frame* frame) {
   JavaType value;

    value.tag = CAT2;
    value.type_double = frame->operandStack.top().type_double;
    frame->operandStack.pop();
    frame->jvmStack->pop();

    Frame* invoker = &(frame->jvmStack->top());
    invoker->operandStack.push(value);
    return invoker->localPC;
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
    MethodArea * methodArea = classLoader->getMethodArea();
    uint16_t index = ((uint16_t)byte1 << 8) | byte2;

    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;
    string nameAndType = frame->constantPool[index-1]->getInfo(frame->constantPool).second;
    int j = 0;

    while (j < nameAndType.size() && nameAndType[j+1] != ':') {
        j++;
    }
    string fieldName = nameAndType.substr(0,j);
    string fieldDescriptor = nameAndType.substr(j+3,nameAndType.size());

    if (className.compare("java/lang/System") == 0) {
        return ++frame->localPC;
    }
    else {
        if (!methodArea->isClassInitialized(className)) {
            methodArea->setClassAsInitialized(className);

            ClassFile aux = classLoader->loadClassFile(className + ".class");
            classLoader->loadSuperClasses(&aux);
            ClassFile * classFile = classLoader->getClassFromMethodArea(className);
            vector<CPInfo*> constantPool = classFile->getConstantPool();
            vector<MethodInfo*> methods = classFile->getMethods();
            MethodInfo* method;

            bool foundClinit = false;
            for (int i = 0; i < classFile->getMethodsCount() && !foundClinit; i++) {
                method = methods[i];
                uint16_t nameIndex = method->getNameIndex();
                uint16_t descriptorIndex = method->getDescriptorIndex();
                string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
                string classDescriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
                if (name.compare("<clinit>") == 0 && classDescriptor.compare("()V") == 0) {
                    foundClinit = true;
                }
            }

            if (foundClinit) {
                Frame clinitMethodFrame(constantPool, method, frame->jvmStack);
                frame->jvmStack->push(clinitMethodFrame);
                frame->localPC-=2;
                return clinitMethodFrame.localPC;
            }
        }

        ClassFile * classFile = methodArea->getClassFile(className);
        vector<CPInfo*> constantPool = classFile->getConstantPool();
        vector<FieldInfo*> fields = classFile->getFields();
        FieldInfo* field;
        bool foundField = false;

        for (int i = 0; i < classFile->getFieldsCount() && !foundField; i++) {
            field = fields[i];
            uint16_t nameIndex = field->getNameIndex();
            uint16_t descriptorIndex = field->getDescriptorIndex();
            string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
            string descriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
            if (name.compare(fieldName) == 0 && descriptor.compare(fieldDescriptor) == 0) {
                foundField = true;
            }
        }

        if (!foundField) {
            printf("getstatic: o field especificado nao pode ser resolvido! Deve estar em uma superclasse ou superinterface! Falta implementar!\n");
            exit(0);
        }

        if (fieldDescriptor.compare("C") == 0) {
            frame->operandStack.push(field->staticValue);
        }
        else if (fieldDescriptor.compare("I") == 0) {
            frame->operandStack.push(field->staticValue);
        }
        else if (fieldDescriptor.compare("F") == 0) {
            frame->operandStack.push(field->staticValue);
        }
        else if (fieldDescriptor.compare("D") == 0) {
            frame->operandStack.push(field->staticValue);
        }
        else if (fieldDescriptor.compare("J") == 0) {
            frame->operandStack.push(field->staticValue);
        }
        else if (fieldDescriptor.compare("Z") == 0) {
            frame->operandStack.push(field->staticValue);
        }
        else {
            printf("getstatic: tipo do descritor nao reconhecido: %s\n", fieldDescriptor.c_str());
            exit(0);
        }
    }

    return ++frame->localPC;
}
uint32_t Instruction::putstaticFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    MethodArea * methodArea = classLoader->getMethodArea();

    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;
    string nameAndType = frame->constantPool[index-1]->getInfo(frame->constantPool).second;
    int j = 0;

    while (j < nameAndType.size() && nameAndType[j+1] != ':') {
        j++;
    }
    string fieldName = nameAndType.substr(0,j);
    string fieldDescriptor = nameAndType.substr(j+3,nameAndType.size());

    if (!methodArea->isClassInitialized(className)) {
        methodArea->setClassAsInitialized(className);

        ClassFile aux = classLoader->loadClassFile(className + ".class");
        classLoader->loadSuperClasses(&aux);
        ClassFile * classFile = classLoader->getClassFromMethodArea(className);
        vector<CPInfo*> constantPool = classFile->getConstantPool();
        vector<MethodInfo*> methods = classFile->getMethods();
        MethodInfo* method;

        bool foundClinit = false;
        for (int i = 0; i < classFile->getMethodsCount() && !foundClinit; i++) {
            method = methods[i];
            uint16_t nameIndex = method->getNameIndex();
            uint16_t descriptorIndex = method->getDescriptorIndex();
            string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
            string classDescriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
            if (name.compare("<clinit>") == 0 && classDescriptor.compare("()V") == 0) {
                foundClinit = true;
            }
        }

        if (foundClinit) {
            Frame clinitMethodFrame(constantPool, method, frame->jvmStack);
            frame->jvmStack->push(clinitMethodFrame);
            frame->localPC-=2;
            return clinitMethodFrame.localPC;
        }
    }

    ClassFile * classFile = methodArea->getClassFile(className);
    vector<CPInfo*> constantPool = classFile->getConstantPool();
    vector<FieldInfo*> fields = classFile->getFields();
    FieldInfo* field;
    bool foundField = false;

    for (int i = 0; i < classFile->getFieldsCount() && !foundField; i++) {
        field = fields[i];
        uint16_t nameIndex = field->getNameIndex();
        uint16_t descriptorIndex = field->getDescriptorIndex();
        string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
        string descriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
        if (name.compare(fieldName) == 0 && descriptor.compare(fieldDescriptor) == 0) {
            foundField = true;
        }
    }

    if (!foundField) {
        printf("putstatic: o field especificado nao pode ser resolvido! Deve estar em uma superclasse ou superinterface! Falta implementar!\n");
        exit(0);
    }

    if (fieldDescriptor.compare("C") == 0) {
        field->staticValue.tag = CAT1;
        field->staticValue.type_char = frame->operandStack.top().type_char;
        frame->operandStack.pop();
    }
    else if (fieldDescriptor.compare("I") == 0) {
        field->staticValue.tag = CAT1;
        field->staticValue.type_int = frame->operandStack.top().type_int;
        frame->operandStack.pop();
    }
    else if (fieldDescriptor.compare("F") == 0) {
        field->staticValue.tag = CAT1;
        field->staticValue.type_float = frame->operandStack.top().type_float;
        frame->operandStack.pop();
    }
    else if (fieldDescriptor.compare("D") == 0) {
        field->staticValue.tag = CAT2;
        field->staticValue.type_double = frame->operandStack.top().type_double;
        frame->operandStack.pop();
    }
    else if (fieldDescriptor.compare("J") == 0) {
        field->staticValue.tag = CAT2;
        field->staticValue.type_long = frame->operandStack.top().type_long;
        frame->operandStack.pop();
    }
    else if (fieldDescriptor.compare("Z") == 0) {
        field->staticValue.tag = CAT1;
        field->staticValue.type_boolean = frame->operandStack.top().type_boolean;
        frame->operandStack.pop();
    }
    else {
        printf("putstatic: tipo do descritor nao reconhecido: %s\n", fieldDescriptor.c_str());
        exit(0);
    }

    return ++frame->localPC;
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
            else if (descriptor.compare("(C)V") == 0) {
                uint8_t character = frame->operandStack.top().type_char;
                frame->operandStack.pop();
                cout << character << endl;
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
            else if (descriptor.compare("(Z)V") == 0) {
                uint32_t integer = (uint32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();

                if (integer == 1) {
                    cout << "true" << endl;
                }
                else if (integer == 0) {
                    cout << "false" << endl;
                }
                else {
                    cout << "Erro no tipo booleano!\\n" << endl;
                    exit(0);
                }
            }
            else if (descriptor.compare("()V") == 0) {
                cout << endl;
            }
            else {
                printf("invokevirtualFunction: tipo do descritor nao reconhecido: %s\n", descriptor.c_str());
                exit(0);
            }
        }
        else if (methodName.compare("print") == 0) {
            if (descriptor.compare("(Ljava/lang/String;)V") == 0) {
                string* stringReference = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();
                cout << *stringReference;
            }
            else if (descriptor.compare("(I)V") == 0) {
                int32_t integer = (int32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();
                cout << integer;
            }
            else if (descriptor.compare("(F)V") == 0) {
                float floatNumber;
                memcpy(&floatNumber, &(frame->operandStack.top().type_float), sizeof(float));
                frame->operandStack.pop();
                cout << floatNumber;
            }
            else if (descriptor.compare("(D)V") == 0) {
                double doubleNumber;
                memcpy(&doubleNumber, &(frame->operandStack.top().type_double), sizeof(double));
                frame->operandStack.pop();
                cout << doubleNumber;
            }
            else if (descriptor.compare("(J)V") == 0) {
                int64_t longNumber = (int64_t)frame->operandStack.top().type_long;
                frame->operandStack.pop();
                cout << longNumber;
            }
            else if (descriptor.compare("(Z)V") == 0) {
                uint32_t integer = (uint32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();

                if (integer == 1) {
                    cout << "true";
                }
                else if (integer == 0) {
                    cout << "false";
                }
                else {
                    cout << "Erro no tipo booleano!";
                    exit(0);
                }
            }
            else if (descriptor.compare("()V") == 0) {
                //Nao faz nada
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
    else if (className.compare("java/lang/StringBuilder") == 0) {
        if (methodName.compare("append") == 0) {
            if (descriptor.compare("(Ljava/lang/String;)Ljava/lang/StringBuilder;") == 0) {
                string* str1 = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();
                string* str2 = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();

                JavaType objectref;
                objectref.type_reference = (uint64_t)new string(*str2 + *str1);
                objectref.tag = CAT1;
                frame->operandStack.push(objectref);
            }
            else if (descriptor.compare("(I)Ljava/lang/StringBuilder;") == 0) {
                int32_t integer = (int32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();
                string* str = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();

                JavaType objectref;
                objectref.type_reference = (uint64_t)new string(*str + to_string(integer));
                objectref.tag = CAT1;
                frame->operandStack.push(objectref);
            }
            else if (descriptor.compare("(J)Ljava/lang/StringBuilder;") == 0) {
                int64_t longNumber = (int64_t)(frame->operandStack.top().type_long);
                frame->operandStack.pop();
                string* str = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();

                JavaType objectref;
                objectref.type_reference = (uint64_t)new string(*str + to_string(longNumber));
                objectref.tag = CAT1;
                frame->operandStack.push(objectref);
            }
            else if (descriptor.compare("(F)Ljava/lang/StringBuilder;") == 0) {
                uint32_t integer = (uint32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();
                string* str = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();

                float floatNumber;
                memcpy(&floatNumber, &integer, sizeof(float));

                JavaType objectref;
                objectref.type_reference = (uint64_t)new string(*str + to_string(floatNumber));
                objectref.tag = CAT1;
                frame->operandStack.push(objectref);
            }
            else if (descriptor.compare("(D)Ljava/lang/StringBuilder;") == 0) {
                uint64_t longNumber = (uint64_t)(frame->operandStack.top().type_double);
                frame->operandStack.pop();
                string* str = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();

                double doubleNumber;
                memcpy(&doubleNumber, &longNumber, sizeof(double));

                JavaType objectref;
                objectref.type_reference = (uint64_t)new string(*str + to_string(doubleNumber));
                objectref.tag = CAT1;
                frame->operandStack.push(objectref);
            }
            else if (descriptor.compare("(Z)Ljava/lang/StringBuilder;") == 0) {
                uint32_t integer = (uint32_t)(frame->operandStack.top().type_int);
                frame->operandStack.pop();
                string* str = (string*)(frame->operandStack.top().type_reference);
                frame->operandStack.pop();

                JavaType objectref;
                if (integer == 1) {
                    objectref.type_reference = (uint64_t)new string(*str + "true");
                }
                else if (integer == 0) {
                    objectref.type_reference = (uint64_t)new string(*str + "false");
                }
                else {
                    cout << "Erro no tipo booleano durante a concatenacao!";
                    exit(0);
                }
                frame->operandStack.push(objectref);
                objectref.tag = CAT1;
            }
            else {
                printf("invokevirtual: StringBuilder: descritor nao reconhecido: %s\n", descriptor.c_str());
                exit(0);
            }
        }
        else if (methodName.compare("toString") == 0) {
            //Fingindo que estou convertendo em string
        }
        else {
            printf("invokevirtualFunction: Metodo do StringBuilder nao reconhecido: %s\n", methodName.c_str());
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
            exit(0);
        }
    }
    else if (className.compare("java/lang/StringBuilder") == 0) {
        if (methodName.compare("<init>") == 0) {
            frame->operandStack.pop();
        }
    }
    else {
        printf("invokespecial: classe nao reconhecida: %s\n", className.c_str());
        exit(0);
    }

    return ++frame->localPC;
}
uint32_t Instruction::invokestaticFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    uint16_t index = ((uint16_t)byte1 << 8) | byte2;
    MethodArea * methodArea = classLoader->getMethodArea();

    string className = frame->constantPool[index-1]->getInfo(frame->constantPool).first;
    string nameAndType = frame->constantPool[index-1]->getInfo(frame->constantPool).second;
    int j = 0;

    while (j < nameAndType.size() && nameAndType[j+1] != ':') {
        j++;
    }
    string methodName = nameAndType.substr(0,j);
    string descriptor = nameAndType.substr(j+3,nameAndType.size());

    if (!methodArea->isClassInitialized(className)) {
        methodArea->setClassAsInitialized(className);

        ClassFile aux = classLoader->loadClassFile(className + ".class");
        classLoader->loadSuperClasses(&aux);
        ClassFile * classFile = classLoader->getClassFromMethodArea(className);
        vector<CPInfo*> constantPool = classFile->getConstantPool();
        vector<MethodInfo*> methods = classFile->getMethods();
        MethodInfo* method;

        bool foundClinit = false;
        for (int i = 0; i < classFile->getMethodsCount() && !foundClinit; i++) {
            method = methods[i];
            uint16_t nameIndex = method->getNameIndex();
            uint16_t descriptorIndex = method->getDescriptorIndex();
            string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
            string classDescriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
            if (name.compare("<clinit>") == 0 && classDescriptor.compare("()V") == 0) {
                foundClinit = true;
            }
        }

        if (foundClinit) {
            Frame clinitMethodFrame(constantPool, method, frame->jvmStack);
            frame->jvmStack->push(clinitMethodFrame);
            frame->localPC-=2;
            return clinitMethodFrame.localPC;
        }
    }

    ClassFile * classFile = methodArea->getClassFile(className);
    vector<CPInfo*> constantPool = classFile->getConstantPool();
    vector<MethodInfo*> methods = classFile->getMethods();
    MethodInfo* method;
    bool foundMethod = false;

    for (int i = 0; i < classFile->getMethodsCount() && !foundMethod; i++) {
        method = methods[i];
        uint16_t nameIndex = method->getNameIndex();
        uint16_t descriptorIndex = method->getDescriptorIndex();
        string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
        string classDescriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
        if (name.compare(methodName) == 0 && classDescriptor.compare(descriptor) == 0) {
            foundMethod = true;
        }
    }

    if (!foundMethod) {
        printf("Invokestatic: o método especificado nao foi encontrado!\n");
        exit(0);
    }

    Frame staticMethodFrame(constantPool, method, frame->jvmStack);

    int argCnt = -1;
    for (int i = 0; descriptor[i] != ')'; i++) {
        if (descriptor[i] == 'I' || descriptor[i] == 'F') {
            argCnt++;
        }
        else if (descriptor[i] == 'J' || descriptor[i] == 'D') {
            argCnt += 2;
        }
    }
    for (int i = 1; descriptor[i] != ')'; i++) {
        if (descriptor[i] == 'I' || descriptor[i] == 'F') {
            JavaType arg = frame->operandStack.top();
            frame->operandStack.pop();
            staticMethodFrame.localVariables[argCnt] = arg;
            argCnt--;
        }
        else if (descriptor[i] == 'J' || descriptor[i] == 'D') {
            JavaType arg = frame->operandStack.top();
            frame->operandStack.pop();
            argCnt--;
            staticMethodFrame.localVariables[argCnt] = arg;
            argCnt--;
        }
        else {
            cout << "Tipo de descritor nao reconhecido: " << descriptor[i] << endl;
            exit(0);
        }
    }
    frame->jvmStack->push(staticMethodFrame);
    frame->localPC++;
    return staticMethodFrame.localPC;
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
        objectref.tag = CAT1;
        frame->operandStack.push(objectref);
    }
    else if (className.compare("java/lang/StringBuilder") == 0) {
        JavaType objectref;
        objectref.type_reference = (uint64_t)new string("");
        objectref.tag = CAT1;
        frame->operandStack.push(objectref);
    }
    else {
        printf("newOp: ainda nao esta funcionando para casos alem de string do java\n");
        exit(0);
    }
    return ++frame->localPC;
}
uint32_t Instruction::newarrayFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint8_t atype = bytecode[++frame->localPC];

    JavaType count;
    count.type_int = (int32_t)frame->operandStack.top().type_int;
    frame->operandStack.pop();

    vector<JavaType>* array = new vector<JavaType>(count.type_int);

    if (atype == T_BOOLEAN) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT1;
            array->at(i).type_boolean = (int8_t)0;
        }
    }
    else if (atype == T_CHAR) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT1;
            array->at(i).type_char = (int16_t)0;
        }
    }
    else if (atype == T_FLOAT) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT1;
            array->at(i).type_float = (uint32_t)0;
        }
    }
    else if (atype == T_DOUBLE) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT2;
            array->at(i).type_double = (uint64_t)0;
        }
    }
    else if (atype == T_BYTE) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT1;
            array->at(i).type_byte = (int8_t)0;
        }
    }
    else if (atype == T_SHORT) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT1;
            array->at(i).type_short = (int16_t)0;
        }
    }
    else if (atype == T_INT) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT1;
            array->at(i).type_int = (int32_t)0;
        }
    }
    else if (atype == T_LONG) {
        for (int32_t i = 0; i < count.type_int; i++) {
            array->at(i).tag = CAT2;
            array->at(i).type_long = (int64_t)0;
        }
    }
    else {
        printf("newarray: tipo de array indefinido: %u\n", atype);
    }


    JavaType arrayref;
    arrayref.tag = CAT1;
    arrayref.type_reference = (uint64_t)array;
    frame->operandStack.push(arrayref);

    return ++frame->localPC;
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
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if (value.type_reference == JAVA_NULL) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
}
uint32_t Instruction::ifnonnullFunction(Frame* frame) {
    uint8_t* bytecode = frame->getCode();
    uint32_t baseAddress = frame->localPC;
    uint8_t byte1 = bytecode[++frame->localPC];
    uint8_t byte2 = bytecode[++frame->localPC];
    int16_t branchOffset = ((int16_t)byte1 << 8) | byte2;

    JavaType value = frame->operandStack.top();
    frame->operandStack.pop();

    if (value.type_reference != JAVA_NULL) {
        frame->localPC = baseAddress + branchOffset;
        return frame->localPC;
    }

    return ++frame->localPC;
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