#include "../hpp/AttributeInfo.hpp"

void ConstantValueAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    constantValueIndex = twoByteReader.byteCatch(fp);
}

void ConstantValueAttribute::print(std::vector<CPInfo*> trueCpInfo) {
    // CpAttributeInterface utf8Getter;
    // cout << "Constante Value Index: cp info #" << this->constvalue_index << " " << utf8Getter.getUTF8(trueCpInfo, this->constvalue_index - 1) << endl;
}

void LineNumber::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;
    startPC = twoByteReader.byteCatch(fp);
    lineNumber = twoByteReader.byteCatch(fp);
}

void LineNumberTableAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    lineNumberTableLength = twoByteReader.byteCatch(fp);
    lineNumberTable = (LineNumber*)calloc(lineNumberTableLength, sizeof(LineNumber));

    for (int i = 0; i < lineNumberTableLength; i++) {
        lineNumberTable[i].read(fp);
    }
}

void LineNumberTableAttribute::print() {
    // cout << "\nLine Number Table" << endl;
    // for(int i=0;i < this->length ; i++ ){
    //     cout <<"["<< i <<"] || "<< this->line_number_table[i].start_pc << " || " << this->line_number_table[i].lineNumber << endl;
    // }
    // cout << "\n\n";
}

void ExceptionHandler::read(FILE *fp) {
    ByteReader<uint8_t> oneByteReader;


    startPC = oneByteReader.byteCatch(fp);
    endPC = oneByteReader.byteCatch(fp);
    handlerPC = oneByteReader.byteCatch(fp);
    catchType = oneByteReader.byteCatch(fp);
}

void CodeAttribute::read(FILE *fp, vector<CPInfo*> constantPool) {
    ByteReader<uint8_t> oneByteReader;
    ByteReader<uint16_t> twoByteReader;
    ByteReader<uint32_t> fourByteReader;

    maxStack = twoByteReader.byteCatch(fp);
    maxLocals = twoByteReader.byteCatch(fp);
    codeLength = fourByteReader.byteCatch(fp);

    code = (uint8_t *)calloc(codeLength, sizeof(uint8_t));
    for (int i = 0; i < codeLength; i++){
        code[i] = oneByteReader.byteCatch(fp);
    }

    exceptionTableLength = twoByteReader.byteCatch(fp);

    exceptionTable = (ExceptionHandler*)calloc(exceptionTableLength, sizeof(ExceptionHandler));
    for (int i = 0; i < exceptionTableLength; i++){
        exceptionTable[i].read(fp);
    }

    attributesCount = twoByteReader.byteCatch(fp);
    attributes = (AttributeInfo *)calloc(attributesCount, sizeof(AttributeInfo));
    for (int i = 0; i < attributesCount; i++){
        attributes[i].read(fp, constantPool);
    }
}

void CodeAttribute::print(std::vector<CPInfo*> trueCpInfo) {
    // unsigned int j, k;
    // CpAttributeInterface utf8Getter;
    // Instruction instructions[256];
    // Instruction::init(instructions, 1);


    // cout << "\n[0]Code:" << endl<<endl;
    // for (unsigned i = 0; i < code_length; i++){
    //     int code_num = (int)code[i];

    //     std::cout << i << ": " << instructions[code_num].name;
    //     for (int j = 0; (unsigned)j < instructions[code_num].bytes; j++) {
    //         ++i;
    //         if (code_num == c_ldc) {
    //           uint8_t index = code[i];
    //           uint16_t index_utf8 = 0x00|index;
    //           std::cout << " #" << (int)index << " "
    //                     <<"<" <<utf8Getter.getUTF8(trueCpInfo, index_utf8-1)<< ">";
    //           j++;
    //         }
    //         else if (code_num == c_newarray) {
    //           printf(" %x", code[j]);
    //           switch (code[j]) {
    //             case 4: std::cout << " (bool)"; break;
    //             case 5 : std::cout << " (char)"; break;
    //             case 6 : std::cout << " (float)"; break;
    //             case 7 : std::cout << " (double)"; break;
    //             case 8 : std::cout << " (byte)"; break;
    //             case 9 : std::cout << " (short)"; break;
    //             case 10 : std::cout << " (int)"; break;
    //             case 11 : std::cout << " (long)"; break;
    //           }
    //           j++;
    //         }
    //         else if (code_num == c_multianewarray) {
    //           uint8_t byte1 = code[i];
    //           uint8_t byte2 = code[i+1];
    //           uint8_t dim = code[i+2];
    //           uint16_t index = (byte1<<8)|byte2;
    //           std::string str = utf8Getter.getUTF8(trueCpInfo, index-1);
    //           if (!str.empty()) {
    //             std::cout << " #" << std::dec << index << " " << str;
    //             std::cout << " dim " << (int)dim;
    //           }
    //           j++;
    //         }
    //         else if (code_num == c_anewarray || code_num ==c_checkcast ||
    //             code_num == c_getfield || code_num == c_getstatic ||
    //             code_num == c_instanceof || code_num == c_invokespecial ||
    //             code_num == c_invokestatic || code_num == c_invokevirtual ||
    //             code_num == c_ldc_w || code_num == c_ldc2_w || code_num == c_NEW ||
    //             code_num == c_putfield || code_num == c_putstatic) {

    //             uint8_t byte1 = code[i];
    //             uint8_t byte2 = code[i+1];
    //             uint16_t index = (byte1<<8)|byte2;
    //             std::cout << " #" << std::dec << index << " "
    //                       <<"<" << utf8Getter.getUTF8(trueCpInfo, index-1)<<">";

    //             i++;
    //             j++;
    //         }
    //         else if (code_num == c_GOTO || code_num == c_if_acmpeq ||
    //                 code_num == c_if_acmpne || code_num == c_if_icmpeq ||
    //                 code_num == c_if_icmpne || code_num == c_if_icmplt ||
    //                 code_num == c_if_icmpge || code_num == c_if_icmpgt ||
    //                 code_num == c_if_icmple || code_num == c_iifeq ||
    //                 code_num == c_ifne || code_num == c_iflt || code_num == c_ifge ||
    //                 code_num == c_ifgt || code_num == c_ifle || code_num == c_ifnonull ||
    //                 code_num == c_ifnull || code_num == c_jsr) {
    //             int16_t branchbyte1 = code[i];
    //             int16_t branchbyte2 = code[i+1];
    //             int16_t address = (branchbyte1 << 8) | branchbyte2;
    //             cout << " " << i+address-1 <<" "<< "("<<address<<")" << " ";
    //             i++;
    //             j++;
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;




    // cout << "Exception Table:" << endl <<endl;
    // for (j = 0; j < this->exception_table_length; j++){
    //     cout << "Start PC: " << this->code_exception_table[j].start_pc<< endl;
    //     cout << "End PC: " << this->code_exception_table[j].end_pc<< endl;
    //     cout << "Handler PC: " << this->code_exception_table[j].handler_pc<< endl;
    //     if(code_exception_table[j].catch_type) {
    //     cout << "Catch type: cp info #" << this->code_exception_table[j].catch_type<< " <" <<utf8Getter.getUTF8(trueCpInfo, this->code_exception_table[j].catch_type-1)<<">" << endl;
    //     }
    // }

    // for (k = 0; k < this->attributes_count; k++){
    //     attributes[k].print(trueCpInfo);
    // }
}

void ClassInfo::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;
    innerClassInfoIndex = twoByteReader.byteCatch(fp);
    outerClassInfoIndex = twoByteReader.byteCatch(fp);
    innerNameIndex = twoByteReader.byteCatch(fp);
    innerClassAccessFlags = twoByteReader.byteCatch(fp);
}

void InnerClassesAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    numberOfClasses = twoByteReader.byteCatch(fp);
    classes = (ClassInfo*)calloc(numberOfClasses, sizeof(ClassInfo));

    for (int i = 0; i < numberOfClasses; i++) {
        classes[i].read(fp);
    }   
}

void InnerClassesAttribute::print(std::vector<CPInfo*> trueCpInfo) {
    // cout << "Class length: " << this->class_length<<endl;
}

void ExceptionsAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    numberOfExceptions = twoByteReader.byteCatch(fp);
    execeptionIndexTable = (uint16_t *)calloc(numberOfExceptions, sizeof(uint16_t));
    for (int i = 0; i < numberOfExceptions; i++) {
        execeptionIndexTable[i] = twoByteReader.byteCatch(fp);
    }
}

void ExceptionsAttribute::print(std::vector<CPInfo*> trueCpInfo) {
    // int i;
    // CpAttributeInterface utf8Getter;

    // cout << "Number of exceptions=" << number_exceptions <<endl;
    // for (i = 0; i < number_exceptions; i++){
    //     cout << setw(2) << setfill('0') << "Exception Index Table: cp info #" << this->exception_index_table[i]<< " " << utf8Getter.getUTF8(trueCpInfo, exception_index_table[i]-1) << endl;
    // }
}

void SourceFileAttribute::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;
    sourcefileIndex = twoByteReader.byteCatch(fp);
}

AttributeInfo::~AttributeInfo() {
    //TODO
}

void AttributeInfo::read(FILE * fp, std::vector<CPInfo *> constantPool){
    CPAttributeInterface utf8Getter;
    ByteReader<uint8_t> oneByteReader;
    ByteReader<uint16_t> twoByteReader;
    ByteReader<uint32_t> fourByteReader;

    attributeNameIndex = twoByteReader.byteCatch(fp);
    attributeLength = fourByteReader.byteCatch(fp);
    string attributeName = utf8Getter.getUTF8(constantPool, attributeNameIndex-1);

    if(attributeName == "Code"){
        code.read(fp, constantPool);
    }
    else if(attributeName == "ConstantValue") {
        constantValue.read(fp);
    }
    else if(attributeName == "Exceptions") {
        exceptions.read(fp);
    }
    else if(attributeName == "InnerClasses") {
        innerClasses.read(fp);
    }
    else if(attributeName == "SourceFile") {
        sourceFile.read(fp);
    }
    else if(attributeName == "LineNumberTable") {
        lineNumberTable.read(fp);
    }
    else {
        cout << "AttributeName not recognized: " << attributeName << endl;
        info = (uint8_t*)calloc(attributeLength, sizeof(uint8_t));
        /* Ignore attribute if it doesn't exist */
        for(int i = 0; i < attributeLength ; i++) {
            info[i] = oneByteReader.byteCatch(fp);
        }
    }
}

void AttributeInfo::print(std::vector<CPInfo *> trueCpInfo) {
    // CpAttributeInterface utf8Getter;
    // std::string attribute_name = utf8Getter.getUTF8(trueCpInfo, this->name_index-1);

    // cout << setw(2) << setfill('0') << "Attribute Name Index: cp info #" << this->name_index<< " <"<< attribute_name << ">" <<endl;
    // cout << setw(2) << setfill('0') << "Attribute Length: " << this->length<< endl;

    // if(attribute_name == "Code"){
    //     code.print(trueCpInfo);
    // }

    // else if(attribute_name == "ConstantValue"){
    //     constant_value.print(trueCpInfo);
    // }

    // else if(attribute_name == "Exceptions"){
    //     exception.print(trueCpInfo);
    // }
    // else if(attribute_name == "InnerClass"){
    //     inner_class.print(trueCpInfo);
    // }
    // else if(attribute_name == "SourceFile"){
    //     sourceFile.print(trueCpInfo);
    // }
    // else if(attribute_name == "LineNumberTable"){
    //     lineNumber.print();
    // }
}