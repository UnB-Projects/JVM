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

void ClassPrinter::print(ClassFile classFile){
    vector<CPInfo*> a = classFile.getConstantPool();
    printGeneralInformation();

    
    /* Print do vetor de constant pool */
/*
    std::cout << "------------------------------ConstantPool------------------------------ \n\n\n";
    for(unsigned i = 0; i < a.size(); i++) {
      switch (a[i]->getTag){
        case CONSTANT_Fieldref:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " << "CONSTANT_Fieldref_info" <<endl;
          std::cout << "\tClass name: cp info #"  << a[i]->Fieldref.class_index;
          //std::cout <<" <" << a[a[a[i]->Fieldref.class_index-1]->Class.name_index -1]->UTF8.bytes << ">" << endl;
          //std::cout <<"\tName and Type: cp info #"  << a[i]->Fieldref.name_and_type_index;
          //std::cout << " <" << a[a[a[i]->Fieldref.name_and_type_index-1]->NameAndType.name_index -1]->UTF8.bytes << " : " << a[a[a[i]->Fieldref.name_and_type_index-1]->NameAndType.descriptor_index -1]->UTF8.bytes << ">" << endl << endl;
          break;
        
        case CONSTANT_Methodref:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " << "CONSTANT_Methodref_info" <<endl;
          std::cout << "\tClass name: cp info #"  << a[i]->Methodref.class_index ;
          std::cout <<" <" << a[a[a[i]->Methodref.class_index-1]->Class.name_index -1]->UTF8.bytes << ">" << endl;
          std::cout <<"\tName and Type: cp info #" << a[i]->Methodref.name_and_type_index ;
          std::cout << " <" << a[a[a[i]->Methodref.name_and_type_index-1]->NameAndType.name_index -1]->UTF8.bytes << " : " << a[a[a[i]->Methodref.name_and_type_index-1]->NameAndType.descriptor_index -1]->UTF8.bytes << ">" << endl << endl;
          break;

        case CONSTANT_NameAndType:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " << "CONSTANT_NameAndType_info" <<endl;
          std::cout << "\tName: cp info #"  << a[i]->NameAndType.name_index ;
          std::cout << " <"<< a[a[i]->NameAndType.name_index-1]->UTF8.bytes <<  ">"  <<endl;
          std::cout << "\tDescriptor: cp info #"  << a[i]->NameAndType.descriptor_index ;
          std::cout << " <"<< a[a[i]->NameAndType.descriptor_index-1]->UTF8.bytes <<  ">" << endl << endl;
          break;

        case CONSTANT_String:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] "<< "CONSTANT_String_info" << endl;
          std::cout << "\tString: cp info #"  << a[i]->String.string_index;
          std::cout << " <"<< a[a[i]->String.string_index-1]->UTF8.bytes <<  ">"  <<endl << endl;
          break;

        case CONSTANT_Utf8:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] "<< "CONSTANT_UTF8_info" << endl;
          std::cout << "\tLength of byte array: "  << a[i]->UTF8.length <<endl;
          std::cout << "\tLength of string: "  << a[i]->UTF8.length <<endl;
          std::cout << "\tString: "  << a[i]->UTF8.bytes << endl << endl;
          // std::cout << setw(2) << setfill('0') << i+1 << " : " << setw(2) << setfill('0') << "String = "  << a[i]->UTF8.length << endl<<endl;
          break;

        case CONSTANT_Class:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] "<< "CONSTANT_Class_info" << endl;
          std::cout << "\tClass name: cp info #"  << a[i]->Class.name_index ;
          std::cout << " <"<< a[a[i]->Class.name_index-1]->UTF8.bytes <<  ">"  <<endl << endl;
          break;

        case CONSTANT_InterfaceMethodref:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " <<  "CONSTANT_InterfaceMethodref_info" << endl;
          std::cout << "\tClass name: "  << a[i]->InterfaceMethodref.class_index << endl;
          std::cout << "\tName and Type: "  << a[i]->InterfaceMethodref.name_and_type_index << endl << endl;
          break;

        case CONSTANT_Integer:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " <<  "CONSTANT_Integer_info" << endl;
          std::cout << "\tBytes: "  << a[i]->Integer.bytes << endl << endl;
          break;

        case CONSTANT_Float:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " << "CONTANT_Float_info" << endl;
          std::cout << "\tBytes: "  << a[i]->Float.bytes << endl << endl;
          break;

        case CONSTANT_Long:
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " << "CONSTANT_Long_info" << endl;
          std::cout << "\tHigh Bytes: "  << a[i]->Long.high_bytes << endl;
          std::cout << "\tLow Bytes: "  << a[i]->Long.low_bytes << endl << endl;
          break;

        case CONSTANT_Double:
          double print_double; /* Transforma os bytes para double */

/*
          uint64_t aux;
          aux = ((uint64_t)a[i]->Double.high_bytes << 32) | a[i]->Double.low_bytes;
          memcpy(&print_double, &aux, sizeof(double));
          std::cout << "["<< setw(2) << setfill('0') << i+1 << "] " << "CONSTANT_Double_info" << endl;
          std::cout << "\tHigh Bytes: 0x";
          printf("%x\n",a[i]->Double.high_bytes );
           
          std::cout << "\tLow Bytes: 0x";
          printf("%x\n",a[i]->Double.low_bytes );
          std::cout << "\tDouble: "  << print_double << endl << endl;
          break;

        case CONSTANT_Empty:
          std::cout <<"[" <<setw(2) << setfill('0') << i+1 << "] (large numeric continued)" << endl << endl;
          break;
 
        default :
          std::cout << "Non-type" << endl;
      }
    }

   /* std::cout << "------------------------------Fields------------------------------" << endl << endl;

    vector<FieldInfo *> fieldInfo = classloader.getFields();
    int countFields = fieldInfo.size();
    for(int i=0;i<countFields;i++){
      std::cout << "[" << i << "]" << endl;
      std::cout <<"Name = constantpool[" << fieldInfo[i]->name_index<<"] " <<"<"<<a[fieldInfo[i]->name_index-1]->UTF8.bytes<<">"<< endl;
      std::cout <<"Descriptor = constantpool[" << fieldInfo[i]->descriptor_index<<"] "<< "<"<< a[fieldInfo[i]->descriptor_index-1]->UTF8.bytes<<">"<<endl;
      std::cout <<"Access flag = " << "0x" << setw(4) << setfill('0') << fieldInfo[i]->access_flags  << Flag_names(fieldInfo[i]->access_flags, 0) <<endl << endl;
    }
    if(countFields == 0 ){
      std::cout << "EMPTY" << endl;
    }*/

    /* Print do vetor de interfaces */
/*   std::vector<InterfaceInfo*> interfaces = classloader.getInterfaces();
    std::cout << "------------------------------Interfaces------------------------------" << endl << endl;
    for (unsigned j = 0; j < interfaces.size(); j++) {
        std::cout << x.getUTF8(classloader.getConstPool(), interfaces[j]->interface_table -1);
    }
    std::cout << "\nEMPTY" << endl;
    /* Fim do Print do vetor de interfaces */

    /* Printar o method */
/*    std::cout << "------------------------------Method------------------------------" << endl << endl;
    vector<MethodInfo *> methods = classloader.getMethods();
    int countMethod = methods.size();
    for(int i=0;i<countMethod;i++){
      std::cout << "\n[" << i << "]" << a[methods[i]->name_index-1]->UTF8.bytes << endl;
      std::cout <<"Name: cp info #" << methods[i]->name_index <<" <"<<a[methods[i]->name_index-1]->UTF8.bytes<<">"<< endl;
      std::cout <<"Descriptor: cp info #" << methods[i]->descriptor_index<<" <"<< a[methods[i]->descriptor_index-1]->UTF8.bytes<<">"<<endl;
      std::cout <<"Access flag: " << "0x" << setw(4) << setfill('0') << methods[i]->access_flags<< Flag_names(methods[i]->access_flags, 0) <<endl  << endl;
      for(int j=0;j<methods[i]->attributes_count; j++){
        methods[i]->attributes[j].print(a);
      }
    }


    /* Fim do print method */
    /* Print do vetor de attributes */
/*    vector<AttributeInfo *> attributes = classloader.getAttributes();
    std::cout << "\n------------------------------Attributes------------------------------" << endl << endl;
    for (unsigned k = 0 ; k < attributes.size(); k++) {
        std::cout << "[" << k << "]" ;
        attributes[k]->print(a);
    }

    /* Fim do print attributes */
    //fclose(fp);
  /**Finalizar o leitor*/
  exit(0);
}