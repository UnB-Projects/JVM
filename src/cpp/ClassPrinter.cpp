#include "../hpp/ClassPrinter.hpp"

string ClassPrinter::interpretClassFlags(uint16_t accessFlags) {
    vector<string> identifiedFlags;
    ostringstream outputFlagsStream;

    if (accessFlags & ClassFile::ACC_PUBLIC) {
       identifiedFlags.push_back("public"); 
    }
    if (accessFlags & ClassFile::ACC_FINAL) {
       identifiedFlags.push_back("final"); 
    }
    // For ClassFile structures, 0x0020 is ACC_SUPER, which has historical significance only
    // if (accessFlags & ClassFile::ACC_SUPER) {
    //    identifiedFlags.push_back("super"); 
    // }
    if (accessFlags & ClassFile::ACC_INTERFACE) {
       identifiedFlags.push_back("interface"); 
    }
    if (accessFlags & ClassFile::ACC_ABSTRACT) {
       identifiedFlags.push_back("abstract"); 
    }
    if (accessFlags & ClassFile::ACC_SYNTHETIC) {
       identifiedFlags.push_back("synthetic"); 
    }
    if (accessFlags & ClassFile::ACC_ANNOTATION) {
       identifiedFlags.push_back("annotation"); 
    }
    if (accessFlags & ClassFile::ACC_ENUM) {
       identifiedFlags.push_back("enum"); 
    }

    outputFlagsStream << "[";
    if (!identifiedFlags.empty()) {
        copy(identifiedFlags.begin(), identifiedFlags.end()-1, ostream_iterator<string>(outputFlagsStream, " "));
        outputFlagsStream << identifiedFlags.back();
    }
    outputFlagsStream << "]";

    return outputFlagsStream.str();
}

string ClassPrinter::interpretMethodFlags(uint16_t accessFlags) {
    vector<string> identifiedFlags;
    ostringstream outputFlagsStream;

    if (accessFlags & MethodInfo::ACC_PUBLIC) {
       identifiedFlags.push_back("public"); 
    }
    if (accessFlags & MethodInfo::ACC_PRIVATE) {
       identifiedFlags.push_back("private"); 
    }
    if (accessFlags & MethodInfo::ACC_PROTECTED) {
       identifiedFlags.push_back("protected"); 
    }
    if (accessFlags & MethodInfo::ACC_STATIC) {
       identifiedFlags.push_back("static"); 
    }
    if (accessFlags & MethodInfo::ACC_FINAL) {
       identifiedFlags.push_back("final"); 
    }
    if (accessFlags & MethodInfo::ACC_SYNCHRONIZED) {
       identifiedFlags.push_back("synchronized"); 
    }
    if (accessFlags & MethodInfo::ACC_BRIDGE) {
       identifiedFlags.push_back("bridge"); 
    }
    if (accessFlags & MethodInfo::ACC_VARARGS) {
       identifiedFlags.push_back("varargs"); 
    }
    if (accessFlags & MethodInfo::ACC_NATIVE) {
       identifiedFlags.push_back("native"); 
    }
    if (accessFlags & MethodInfo::ACC_ABSTRACT) {
       identifiedFlags.push_back("abstract"); 
    }
    if (accessFlags & MethodInfo::ACC_STRICT) {
       identifiedFlags.push_back("strict"); 
    }
    if (accessFlags & MethodInfo::ACC_SYNTHETIC) {
       identifiedFlags.push_back("synthetic"); 
    }

    outputFlagsStream << "[";
    if (!identifiedFlags.empty()) {
        copy(identifiedFlags.begin(), identifiedFlags.end()-1, ostream_iterator<string>(outputFlagsStream, " "));
        outputFlagsStream << identifiedFlags.back();
    }
    outputFlagsStream << "]";

    return outputFlagsStream.str();
}

ClassPrinter::ClassPrinter(ClassFile classFile) {
    this->classFile = classFile;
}

void ClassPrinter::printGeneralInformation() {
    CPAttributeInterface attrInterface;

    cout << "------------------------------General Information------------------------------" << endl;
    cout << "Magic Number:        " << "0x" << hex << classFile.getMagic() << endl;
    cout << "Minor version:       " << dec << classFile.getMinorVersion() << endl;
    cout << "Major version:       " << dec << classFile.getMajorVersion() << endl;
    cout << "Constant pool count: " << dec << classFile.getConstantPoolCount() << endl;
    cout << "Access flags:        " << "0x" << setw(4) << setfill('0') << hex << classFile.getAccessFlags() << " " << interpretClassFlags(classFile.getAccessFlags()) << endl;
    cout << "ThisClass:           " <<"cp_info# " << dec << classFile.getThisClass() << "<" << attrInterface.getUTF8(classFile.getConstantPool(), classFile.getThisClass()-1) << ">" << endl;
    cout << "SuperClass:          " <<"cp_info# " << dec << classFile.getSuperClass() <<"<" << attrInterface.getUTF8(classFile.getConstantPool(), classFile.getSuperClass()-1)<< ">" << endl;
    cout << "Interfaces count :   " << dec << classFile.getInterfacesCount() << endl;
    cout << "Fields count:        " << dec << classFile.getFieldsCount() << dec << endl;
    cout << "Methods count:       " << dec << classFile.getMethodsCount() << dec << endl;
    cout << "Atributes count:     " << dec << classFile.getAttributesCount() << endl;
}

void ClassPrinter::printConstantPool() {
    vector<CPInfo*> constantPool = classFile.getConstantPool();

    cout << "------------------------------Constant Pool------------------------------" << endl << endl;
    for (int i = 0; i < classFile.getConstantPoolCount()-1; i++) {
        CPInfo *cpInfo = constantPool[i];
        cout << "[" << i+1 << "]";
        pair<string,string> info;

        switch (cpInfo->getTag()) {
        case CPInfo::CONSTANT_Class:
            info = cpInfo->getInfo(constantPool);
            cout << "CONSTANT_Class_info" << endl;
            cout << "Class name: cp_info #" << cpInfo->getClassInfo().name_index << " <" << info.first  << ">";
            break;
        case CPInfo::CONSTANT_Fieldref:
            info = cpInfo->getInfo(constantPool);
            cout << "CONSTANT_Fieldref_info" << endl;
            cout << "Class name:    cp_info #" << cpInfo->getFieldrefInfo().class_index << " <" << info.first << ">" << endl;
            cout << "Name and type: cp_info #" << cpInfo->getFieldrefInfo().name_and_type_index << " <" << info.second << ">"; 
            break;
        case CPInfo::CONSTANT_Methodref:
            info = cpInfo->getInfo(constantPool);
            cout << "CONSTANT_Methodref_info" << endl;
            cout << "Class name:    cp_info #" << cpInfo->getMethodrefInfo().class_index << " <" << info.first << ">" << endl;
            cout << "Name and type: cp_info #" << cpInfo->getMethodrefInfo().name_and_type_index << " <" << info.second << ">";
            break;
        case CPInfo::CONSTANT_InterfaceMethodref:
            info = cpInfo->getInfo(constantPool);
            cout << "CONSTANT_InterfaceMethodref_info" << endl;
            cout << "Class name:    cp_info #" << cpInfo->getInterfaceMethodrefInfo().class_index << " <" << info.first << ">" << endl;
            cout << "Name and type: cp_info #" << cpInfo->getInterfaceMethodrefInfo().name_and_type_index << " <" << info.second << ">";
            break;    
        case CPInfo::CONSTANT_String:
            info = cpInfo->getInfo(constantPool);
            cout << "CONSTANT_String_info" << endl;
            cout << "String: cp_info #" << cpInfo->getStringInfo().string_index << " <" << info.first << ">";
            break;
        case CPInfo::CONSTANT_Integer:
            cout << "CONSTANT_Integer" << endl;
            cout << "Bytes: " << cpInfo->getInfo(constantPool).first;
            break;
        case CPInfo::CONSTANT_Float:
            cout << "CONSTANT_Float_info" << endl;
            cout << "Bytes: " << cpInfo->getInfo(constantPool).first;
            break;
        case CPInfo::CONSTANT_Long:
            cout << "CONSTANT_Long_info" << endl;
            printf("High Bytes: 0x%08X\n", cpInfo->getLongInfo().high_bytes);
            printf("High Bytes: 0x%08X\n", cpInfo->getLongInfo().low_bytes);
            cout << "Long:       " << cpInfo->getInfo(constantPool).first;
            break;
        case CPInfo::CONSTANT_Double:
            cout << "CONSTANT_Double_info" << endl;
            printf("High Bytes: 0x%08X\n", cpInfo->getDoubleInfo().high_bytes);
            printf("High Bytes: 0x%08X\n", cpInfo->getDoubleInfo().low_bytes);
            cout << "Double:     " << cpInfo->getInfo(constantPool).first;
            break;
        case CPInfo::CONSTANT_NameAndType:
            info = cpInfo->getInfo(constantPool);
            cout << "CONSTANT_NameAndType_info" << endl;
            cout << "Name      :" << "cp_info #" << cpInfo->getNameAndTypeInfo().name_index << " <" << info.first << ">" << endl;
            cout << "Descriptor:" << "cp_info #" << cpInfo->getNameAndTypeInfo().descriptor_index << " <" << info.second << ">";
            break;
        case CPInfo::CONSTANT_Utf8:
            cout << "Constant_Utf8_info" << endl;
            cout << "Length of byte array: " << cpInfo->getUTF8Info().length << endl;
            cout << "Length of string:     " << cpInfo->getUTF8Info().length << endl;
            cout << "String:               " << cpInfo->getInfo(constantPool).first;
            break;
        // case CPInfo::CONSTANT_MethodHandle:
        //     break;
        // case CPInfo::CONSTANT_MethodType:
        //     break;
        // case CPInfo::CONSTANT_InvokeDynamic:
        //     break;
        case CPInfo::CONSTANT_Empty:
            cout << "(large numeric continued)";
            break;
        default:
            break;
        }
        cout << endl << endl;
    }
}

void ClassPrinter::printInterfaces() {

}

void ClassPrinter::printFields() {
    
}

void ClassPrinter::printMethods() {
    vector<CPInfo*> constantPool = classFile.getConstantPool();
    vector<MethodInfo*> methods = classFile.getMethods();

    cout << "******************************Methods******************************" << endl << endl;
    cout << "Displayed members---------------------------------------------" << endl << endl;
    cout << "Member count: " << classFile.getMethodsCount() << endl << endl;

    for (int i = 0; i < classFile.getMethodsCount(); i++) {
        MethodInfo* method = methods[i];
        uint16_t nameIndex = method->getNameIndex();
        uint16_t descriptorIndex = method->getDescriptorIndex();
        string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
        string descriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
        uint16_t accessFlags = method->getAccessFlags();
        
        cout << "[" << i << "]" << name << endl;
        cout << "Name      :   " << "cp_info #" << nameIndex << " <" << name << ">" << endl;
        cout << "Descriptor:   " << "cp_info #" << descriptorIndex << " <" << descriptor << ">" << endl;
        printf("Access flags: 0x%04X <%s>\n", accessFlags, interpretMethodFlags(accessFlags).c_str());
        cout << endl;

        for (int j = 0; j < method->getAttributesCount(); j++) {
            printAttributes(method->getAttributes());
        }
        
    }
    
    
}

void ClassPrinter::printSourceFileInfo(SourceFileAttribute* attribute) {
    uint16_t sourceFileIndex = attribute->getSourceFileIndex();
    vector<CPInfo*> constantPool = classFile.getConstantPool();
    CPInfo* info = constantPool[sourceFileIndex-1];

    cout << "Source file name index: cp_info #" << sourceFileIndex << " <" << info->getInfo(constantPool).first << ">" << endl;
}

void ClassPrinter::printCodeInfo(CodeAttribute* attribute) {
    vector<CPInfo*> constantPool = classFile.getConstantPool();
    uint8_t* bytecode = attribute->getCode();
    InstructionSet instructionsSet;
    uint32_t instructionsCount = instructionsSet.getInstructionsCount();
    Instruction* instructions = instructionsSet.getInstructionSet();
    
    cout << "Bytecode-----------" << endl;
    for (int i = 0; i < attribute->getCodeLength(); i++) {
        uint8_t opcode = bytecode[i];
        Instruction instruction = instructions[opcode];

        cout << i << ": " << instruction.getMnemonic() << " ";

        //Operacoes que nao tem bytes adicionais
        if (instruction.getBytesCount() == 0) {
            cout << endl;
        }
        else if (instruction.getBytesCount() == 1) {
            int byte = bytecode[++i];

            //Operacoes que exigem referencia a constant pool
            if (opcode == Instruction::ldc) {
                int index = byte;
                cout << "#" << index << " <" << constantPool[index-1]->getInfo(constantPool).first << ">" << endl;
            }
            else if((opcode == Instruction::bipush) ||
                    (opcode >= Instruction::iload && opcode <= Instruction::aload) || 
                    (opcode >= Instruction::istore && opcode <= Instruction::astore) ||
                    (opcode == Instruction::ret) ) {
                cout << byte << endl;
            }
            else if (opcode == Instruction::newarray) {
                int atype = byte;
                cout << atype << " ";
                switch(atype) {
                case Instruction::T_BOOLEAN: cout << "(bool)";   break;
                case Instruction::T_CHAR:    cout << "(char)";   break;
                case Instruction::T_FLOAT:   cout << "(float)";  break;
                case Instruction::T_DOUBLE:  cout << "(double)"; break;
                case Instruction::T_BYTE:    cout << "(byte)";   break;
                case Instruction::T_SHORT:   cout << "(short)";  break;
                case Instruction::T_INT:     cout << "(int)";    break;
                case Instruction::T_LONG:    cout << "(long)";   break;
                }
            }
        }
        else if (instruction.getBytesCount() == 2) {
            int byte1 = bytecode[++i];
            int byte2 = bytecode[++i];
            cout << endl;
        }
    }
    
}

void ClassPrinter::printAttributes(vector<AttributeInfo*> attributes) {
    vector<CPInfo*> constantPool = classFile.getConstantPool();

    for (int i = 0; i < classFile.getAttributesCount(); i++) {
        AttributeInfo* attribute = attributes[i];
        uint16_t nameIndex = attribute->getAttributeNameIndex();
        string attributeName = constantPool[nameIndex-1]->getInfo(constantPool).first;
        uint16_t attributeLength = attribute->getAttributeLength();

        cout << "[" << i << "]" << attributeName << endl;
        cout << "Generic info ---------------------------------------------" << endl << endl;
        cout << "Attribute name index: cp_info #" << nameIndex << " <" << attributeName << ">" << endl;
        cout << "Attribute length:     " << attributeLength << endl << endl;
        cout << "Specific info --------------------------------------------" << endl << endl;
    
        if (attributeName.compare("ConstantValue") == 0) {

        }
        else if (attributeName.compare("Code") == 0) {
            CodeAttribute codeAttribute = attribute->getCodeAttribute();
            printCodeInfo(&codeAttribute);
        }
        else if (attributeName.compare("InnerClasses") == 0) {
            
        }
        else if (attributeName.compare("SourceFile") == 0) {
            SourceFileAttribute sourceFileAttribute = attribute->getSourceFileAttribute();
            printSourceFileInfo(&sourceFileAttribute);
        }
        else if (attributeName.compare("LineNumberTable") == 0) {
            
        }
        else {

        }

        cout << endl << "----------------------------------------------------------" << endl ;

    }
}

void ClassPrinter::print(){
    printGeneralInformation();
    printConstantPool();
    printMethods();
    // cout << "******************************Attributes******************************" << endl << endl;
    // printAttributes(classFile.getAttributes());
}