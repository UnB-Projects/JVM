#include "../hpp/InstructionSet.hpp"

InstructionSet::InstructionSet() {
    this->instructionsCount = 256;

    instructionSet[Instruction::nop] = Instruction("nop", 0);
    instructionSet[Instruction::aconst_null] = Instruction("aconst_null", 0);
    instructionSet[Instruction::iconst_m1] = Instruction("iconst_m1", 0);
    instructionSet[Instruction::iconst_0] = Instruction("iconst_0", 0);
    instructionSet[Instruction::iconst_1] = Instruction("iconst_1", 0);
    instructionSet[Instruction::iconst_2] = Instruction("iconst_2", 0);
    instructionSet[Instruction::iconst_3] = Instruction("iconst_3", 0);
    instructionSet[Instruction::iconst_4] = Instruction("iconst_4", 0);
    instructionSet[Instruction::iconst_5] = Instruction("iconst_5", 0);
    instructionSet[Instruction::lconst_0] = Instruction("lconst_0", 0);
    instructionSet[Instruction::lconst_1] = Instruction("lconst_1", 0);
    instructionSet[Instruction::fconst_0] = Instruction("fconst_0", 0);
    instructionSet[Instruction::fconst_1] = Instruction("fconst_1", 0);
    instructionSet[Instruction::fconst_2] = Instruction("fconst_2", 0);
    instructionSet[Instruction::dconst_0] = Instruction("dconst_0", 0);
    instructionSet[Instruction::dconst_1] = Instruction("dconst_1", 0);
    instructionSet[Instruction::bipush] = Instruction("bipush", 1);
    instructionSet[Instruction::sipush] = Instruction("sipush", 2);
    instructionSet[Instruction::ldc] = Instruction("ldc", 1);
    instructionSet[Instruction::ldc_w] = Instruction("ldc_w", 2);
    instructionSet[Instruction::ldc2_w] = Instruction("ldc2_w", 2);

    //Loads
    instructionSet[Instruction::iload] = Instruction("iload", 1);
    instructionSet[Instruction::lload] = Instruction("lload", 1);
    instructionSet[Instruction::fload] = Instruction("fload", 1);
    instructionSet[Instruction::dload] = Instruction("dload", 1);
    instructionSet[Instruction::aload] = Instruction("aload", 1);
    instructionSet[Instruction::iload_0] = Instruction("iload_0", 0);
    instructionSet[Instruction::iload_1] = Instruction("iload_1", 0);
    instructionSet[Instruction::iload_2] = Instruction("iload_2", 0);
    instructionSet[Instruction::iload_3] = Instruction("iload_3", 0);
    instructionSet[Instruction::lload_0] = Instruction("lload_0", 0);
    instructionSet[Instruction::lload_1] = Instruction("lload_1", 0);
    instructionSet[Instruction::lload_2] = Instruction("lload_2", 0);
    instructionSet[Instruction::lload_3] = Instruction("lload_3", 0);
    instructionSet[Instruction::fload_0] = Instruction("fload_0", 0);
    instructionSet[Instruction::fload_1] = Instruction("fload_1", 0);
    instructionSet[Instruction::fload_2] = Instruction("fload_2", 0);
    instructionSet[Instruction::fload_3] = Instruction("fload_3", 0);
    instructionSet[Instruction::dload_0] = Instruction("dload_0", 0);
    instructionSet[Instruction::dload_1] = Instruction("dload_1", 0);
    instructionSet[Instruction::dload_2] = Instruction("dload_2", 0);
    instructionSet[Instruction::dload_3] = Instruction("dload_3", 0);
    instructionSet[Instruction::aload_0] = Instruction("aload_0", 0);
    instructionSet[Instruction::aload_1] = Instruction("aload_1", 0);
    instructionSet[Instruction::aload_2] = Instruction("aload_2", 0);
    instructionSet[Instruction::aload_3] = Instruction("aload_3", 0);
    instructionSet[Instruction::iaload] = Instruction("iaload", 0);
    instructionSet[Instruction::laload] = Instruction("laload", 0);
    instructionSet[Instruction::faload] = Instruction("faload", 0);
    instructionSet[Instruction::daload] = Instruction("daload", 0);
    instructionSet[Instruction::aaload] = Instruction("aaload", 0);
    instructionSet[Instruction::baload] = Instruction("baload", 0);
    instructionSet[Instruction::caload] = Instruction("caload", 0);
    instructionSet[Instruction::saload] = Instruction("saload", 0);

    //Stores
    instructionSet[Instruction::istore] = Instruction("istore", 1);
    instructionSet[Instruction::lstore] = Instruction("lstore", 1);
    instructionSet[Instruction::fstore] = Instruction("fstore", 1);
    instructionSet[Instruction::dstore] = Instruction("dstore", 1);
    instructionSet[Instruction::astore] = Instruction("astore", 1);
    instructionSet[Instruction::istore_0] = Instruction("istore_0", 0);
    instructionSet[Instruction::istore_1] = Instruction("istore_1", 0);
    instructionSet[Instruction::istore_2] = Instruction("istore_2", 0);
    instructionSet[Instruction::istore_3] = Instruction("istore_3", 0);
    instructionSet[Instruction::lstore_0] = Instruction("lstore_0", 0);
    instructionSet[Instruction::lstore_1] = Instruction("lstore_1", 0);
    instructionSet[Instruction::lstore_2] = Instruction("lstore_2", 0);
    instructionSet[Instruction::lstore_3] = Instruction("lstore_3", 0);
    instructionSet[Instruction::fstore_0] = Instruction("fstore_0", 0);
    instructionSet[Instruction::fstore_1] = Instruction("fstore_1", 0);
    instructionSet[Instruction::fstore_2] = Instruction("fstore_2", 0);
    instructionSet[Instruction::fstore_3] = Instruction("fstore_3", 0);
    instructionSet[Instruction::dstore_0] = Instruction("dstore_0", 0);
    instructionSet[Instruction::dstore_1] = Instruction("dstore_1", 0);
    instructionSet[Instruction::dstore_2] = Instruction("dstore_2", 0);
    instructionSet[Instruction::dstore_3] = Instruction("dstore_3", 0);
    instructionSet[Instruction::astore_0] = Instruction("astore_0", 0);
    instructionSet[Instruction::astore_1] = Instruction("astore_1", 0);
    instructionSet[Instruction::astore_2] = Instruction("astore_2", 0);
    instructionSet[Instruction::astore_3] = Instruction("astore_3", 0);
    instructionSet[Instruction::iastore] = Instruction("iastore", 0);
    instructionSet[Instruction::lastore] = Instruction("lastore", 0);
    instructionSet[Instruction::fastore] = Instruction("fastore", 0);
    instructionSet[Instruction::dastore] = Instruction("dastore", 0);
    instructionSet[Instruction::aastore] = Instruction("aastore", 0);
    instructionSet[Instruction::bastore] = Instruction("bastore", 0);
    instructionSet[Instruction::castore] = Instruction("castore", 0);
    instructionSet[Instruction::sastore] = Instruction("sastore", 0);

    //Stack
    instructionSet[Instruction::pop] = Instruction("pop", 0);
    instructionSet[Instruction::pop2] = Instruction("pop2", 0);
    instructionSet[Instruction::dup] = Instruction("dup", 0);
    instructionSet[Instruction::dup_x1] = Instruction("dup_x1", 0);
    instructionSet[Instruction::dup_x2] = Instruction("dup_x2", 0);
    instructionSet[Instruction::dup2] = Instruction("dup2", 0);
    instructionSet[Instruction::dup2_x1] = Instruction("dup2_x1", 0);
    instructionSet[Instruction::dup2_x2] = Instruction("dup2_x2", 0);
    instructionSet[Instruction::swap] = Instruction("swap", 0);

    //Math
    instructionSet[Instruction::iadd] = Instruction("iadd", 0);
    instructionSet[Instruction::ladd] = Instruction("ladd", 0);
    instructionSet[Instruction::fadd] = Instruction("fadd", 0);
    instructionSet[Instruction::dadd] = Instruction("dadd", 0);
    instructionSet[Instruction::isub] = Instruction("isub", 0);
    instructionSet[Instruction::lsub] = Instruction("lsub", 0);
    instructionSet[Instruction::fsub] = Instruction("fsub", 0);
    instructionSet[Instruction::dsub] = Instruction("dsub", 0);
    instructionSet[Instruction::imul] = Instruction("imul", 0);
    instructionSet[Instruction::lmul] = Instruction("lmul", 0);
    instructionSet[Instruction::fmul] = Instruction("fmul", 0);
    instructionSet[Instruction::dmul] = Instruction("dmul", 0);
    instructionSet[Instruction::idiv] = Instruction("idiv", 0);
    instructionSet[Instruction::ldivOp] = Instruction("ldiv", 0);
    instructionSet[Instruction::fdiv] = Instruction("fdiv", 0);
    instructionSet[Instruction::ddiv] = Instruction("ddiv", 0);
    instructionSet[Instruction::irem] = Instruction("irem", 0);
    instructionSet[Instruction::lrem] = Instruction("lrem", 0);
    instructionSet[Instruction::frem] = Instruction("frem", 0);
    instructionSet[Instruction::drem] = Instruction("drem", 0);
    instructionSet[Instruction::ineg] = Instruction("ineg", 0);
    instructionSet[Instruction::lneg] = Instruction("lneg", 0);
    instructionSet[Instruction::fneg] = Instruction("fneg", 0);
    instructionSet[Instruction::dneg] = Instruction("dneg", 0);
    instructionSet[Instruction::ishl] = Instruction("ishl", 0);
    instructionSet[Instruction::lshl] = Instruction("lshl", 0);
    instructionSet[Instruction::ishr] = Instruction("ishr", 0);
    instructionSet[Instruction::lshr] = Instruction("lshr", 0);
    instructionSet[Instruction::iushr] = Instruction("iushr", 0);
    instructionSet[Instruction::lushr] = Instruction("lushr", 0);
    instructionSet[Instruction::iand] = Instruction("iand", 0);
    instructionSet[Instruction::land] = Instruction("land", 0);
    instructionSet[Instruction::ior] = Instruction("ior", 0);
    instructionSet[Instruction::lor] = Instruction("lor", 0);
    instructionSet[Instruction::ixor] = Instruction("ixor", 0);
    instructionSet[Instruction::lxor] = Instruction("lxor", 0);
    instructionSet[Instruction::iinc] = Instruction("iinc", 2);

    //Conversions
    instructionSet[Instruction::i2l] = Instruction("i2l", 0);
    instructionSet[Instruction::i2f] = Instruction("i2f", 0);
    instructionSet[Instruction::i2d] = Instruction("i2d", 0);
    instructionSet[Instruction::l2i] = Instruction("l2i", 0);
    instructionSet[Instruction::l2f] = Instruction("l2f", 0);
    instructionSet[Instruction::l2d] = Instruction("l2d", 0);
    instructionSet[Instruction::f2i] = Instruction("f2i", 0);
    instructionSet[Instruction::f2l] = Instruction("f2l", 0);
    instructionSet[Instruction::f2d] = Instruction("f2d", 0);
    instructionSet[Instruction::d2i] = Instruction("d2i", 0);
    instructionSet[Instruction::d2l] = Instruction("d2l", 0);
    instructionSet[Instruction::d2f] = Instruction("d2f", 0);
    instructionSet[Instruction::i2b] = Instruction("i2b", 0);
    instructionSet[Instruction::i2c] = Instruction("i2c", 0);
    instructionSet[Instruction::i2s] = Instruction("i2s", 0);

    //Comparisons
    instructionSet[Instruction::lcmp] = Instruction("lcmp", 0);
    instructionSet[Instruction::fcmpl] = Instruction("fcmpl", 0);
    instructionSet[Instruction::fcmpg] = Instruction("fcmpg", 0);
    instructionSet[Instruction::dcmpl] = Instruction("dcmpl", 0);
    instructionSet[Instruction::dcmpg] = Instruction("dcmpg", 0);
    instructionSet[Instruction::ifeq] = Instruction("ifeq", 2);
    instructionSet[Instruction::ifne] = Instruction("ifne", 2);
    instructionSet[Instruction::iflt] = Instruction("iflt", 2);
    instructionSet[Instruction::ifge] = Instruction("ifge", 2);
    instructionSet[Instruction::ifgt] = Instruction("ifgt", 2);
    instructionSet[Instruction::ifle] = Instruction("ifle", 2);
    instructionSet[Instruction::if_icmpeq] = Instruction("if_icmpeq", 2);
    instructionSet[Instruction::if_icmpne] = Instruction("if_icmpne", 2);
    instructionSet[Instruction::if_icmplt] = Instruction("if_icmplt", 2);
    instructionSet[Instruction::if_icmpge] = Instruction("if_icmpge", 2);
    instructionSet[Instruction::if_icmpgt] = Instruction("if_icmpgt", 2);
    instructionSet[Instruction::if_icmple] = Instruction("if_icmple", 2);
    instructionSet[Instruction::if_acmpeq] = Instruction("if_acmpeq", 2);
    instructionSet[Instruction::if_acmpne] = Instruction("if_acmpne", 2);

    //Control
    instructionSet[Instruction::gotoOp] = Instruction("goto", 2);
    instructionSet[Instruction::jsr] = Instruction("jsr", 2);
    instructionSet[Instruction::ret] = Instruction("ret", 1);
    instructionSet[Instruction::tableswitch] = Instruction("tableswitch", 16); //Ainda nao verifiquei como implementar
    instructionSet[Instruction::lookupswitch] = Instruction("lookupswitch", 8); // Ainda nao verifiquei como implementar
    instructionSet[Instruction::ireturn] = Instruction("ireturn", 0);
    instructionSet[Instruction::lreturn] = Instruction("lreturn", 0);
    instructionSet[Instruction::freturn] = Instruction("freturn", 0);
    instructionSet[Instruction::dreturn] = Instruction("dreturn", 0);
    instructionSet[Instruction::areturn ] = Instruction("areturn", 0);
    instructionSet[Instruction::returnOp] = Instruction("return", 0);

    //References
    instructionSet[Instruction::getstatic] = Instruction("getstatic", 2);
    instructionSet[Instruction::putstatic] = Instruction("putstatic", 2);
    instructionSet[Instruction::getfield] = Instruction("getfield", 2);
    instructionSet[Instruction::putfield] = Instruction("putfield", 2);
    instructionSet[Instruction::invokevirtual] = Instruction("invokevirtual", 2);
    instructionSet[Instruction::invokespecial] = Instruction("invokespecial", 2);
    instructionSet[Instruction::invokestatic] = Instruction("invokestatic", 2);
    instructionSet[Instruction::invokeinterface] = Instruction("invokeinterface", 4);
    instructionSet[Instruction::invokedynamic] = Instruction("invokedynamic", 4);
    instructionSet[Instruction::newOp] = Instruction("new", 2);
    instructionSet[Instruction::newarray] = Instruction("newarray", 1);
    instructionSet[Instruction::anewarray] = Instruction("anewarray", 2);
    instructionSet[Instruction::arraylength] = Instruction("arraylength", 0);
    instructionSet[Instruction::athrow] = Instruction("athrow", 0);
    // As quatro instrucoes seguintes nao precisam ser implementadas
    instructionSet[Instruction::checkcast] = Instruction("checkcast", 2);
    instructionSet[Instruction::instanceof] = Instruction("instanceof", 2);
    instructionSet[Instruction::monitorenter] = Instruction("monitorenter", 0);
    instructionSet[Instruction::monitorexit] = Instruction("monitorexit", 0);

    //Extended
    instructionSet[Instruction::wide] = Instruction("wide", 5); //wide eh uma instrucao que tem dois formatos!! tem que ver isso talkey
    instructionSet[Instruction::multianewarray] = Instruction("multianewarray", 3);
    instructionSet[Instruction::ifnull] = Instruction("ifnull", 2);
    instructionSet[Instruction::ifnonnull] = Instruction("ifnonnull", 2);
    instructionSet[Instruction::goto_w] = Instruction("goto_w", 4);
    instructionSet[Instruction::jsr_w] = Instruction("jsr_w", 4);
}