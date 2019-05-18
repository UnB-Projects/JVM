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
    cout << "Access flags:        " << "0x" << setw(4) << setfill('0') << hex << classFile.getAccessFlags() << interpretClassFlags(classFile.getAccessFlags()) << endl;
    cout << "ThisClass:           " <<"cp_info# " << dec << classFile.getThisClass() << "<" << attrInterface.getUTF8(classFile.getConstantPool(), classFile.getThisClass()-1) << ">" << endl;
    cout << "SuperClass:          " <<"cp_info# " << dec << classFile.getSuperClass() <<"<" << attrInterface.getUTF8(classFile.getConstantPool(), classFile.getSuperClass()-1)<< ">" << endl;
    cout << "Interfaces count :   " << dec << classFile.getInterfacesCount() << endl;
    cout << "Fields count:        " << dec << classFile.getFieldsCount() << dec << endl;
    cout << "Methods count:       " << dec << classFile.getMethodsCount() << dec << endl;
    cout << "Atributes count:     " << dec << classFile.getAttributesCount() << endl;
}

void ClassPrinter::printConstantPool() {
    CPAttributeInterface attrInterface;
    vector<CPInfo*> constantPool = classFile.getConstantPool();

    cout << "------------------------------ConstantPool------------------------------ \n\n\n";
    for (int i = 0; i < classFile.getConstantPoolCount()-1; i++) {
        CPInfo *cpInfo = constantPool[i];

        cout << "[" << i+1 << "]";

        switch (cpInfo->getTag()) {
        case CPInfo::CONSTANT_Class:
            cout << "Class name: cp_info #" << cpInfo->getClassInfo().name_index
                 << "<" << attrInterface.getUTF8(constantPool, cpInfo->getClassInfo().name_index-1) << ">";
            break;
        case CPInfo::CONSTANT_Fieldref:
            // cout << "Class name cp_info #" << cpInfo->getFieldrefInfo().class_index << "<" << attrInterface << ">" << endl;
            break;
        case CPInfo::CONSTANT_Methodref:
            break;
        case CPInfo::CONSTANT_InterfaceMethodref:
            break;    
        case CPInfo::CONSTANT_String:
            break;
        case CPInfo::CONSTANT_Integer:
            break;
        case CPInfo::CONSTANT_Float:
            break;
        case CPInfo::CONSTANT_Long:
            break;
        case CPInfo::CONSTANT_Double:
            break;
        case CPInfo::CONSTANT_NameAndType:
            break;
        case CPInfo::CONSTANT_Utf8:
            break;
        case CPInfo::CONSTANT_MethodHandle:
            break;
        case CPInfo::CONSTANT_MethodType:
            break;
        case CPInfo::CONSTANT_InvokeDynamic:
            break;
        case CPInfo::CONSTANT_Empty:
            break;
        default:
            break;
        }
        cout << endl;
    }
}

void ClassPrinter::print(ClassFile classFile){
    vector<CPInfo*> a = classFile.getConstantPool();
    printGeneralInformation();
    printConstantPool();
}