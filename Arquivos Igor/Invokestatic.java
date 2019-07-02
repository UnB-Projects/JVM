class Invokestatic {
    public static void main(String[] args) {
        System.out.println(somaInt(1, 2));
        System.out.println(subInt(1, 2));
        System.out.println(divInt(4, 2));
        System.out.println(divInt(6, 2));
        System.out.println(divInt(3, 2));
        // System.out.println(divInt(1, 0));
        System.out.println(mulInt(1,2));
        System.out.println(mulInt(3,2));
        System.out.println(mulInt(-3,2));
        System.out.println(mulInt(3,-2));
        System.out.println(mod(2, 1));
        System.out.println(mod(3, 2));
        System.out.println(mod(-3, 2));
        System.out.println(mod(-3, -2));
        System.out.println(neg(7));
        System.out.println(sll(2, 4));
        System.out.println(srl(32, 4));
        System.out.println(sru(-32, 4));
        System.out.println(and(3, 5));
        System.out.println(or(3, 5));
        System.out.println(xor(3, 5));
        System.out.println(not(3));
        System.out.println(inc(9));
        System.out.println(dec(9));

    };

    static int somaInt(int a, int b) {
        return a + b;
    }
    static int subInt(int a, int b) {
        return a - b;
    }
    static int divInt(int a, int b) {
        return a / b;
    }
    static int mulInt(int a, int b) {
        return a * b;
    }
    static int mod(int a, int b) {
        return a % b;
    }
    static int neg (int a) {
        return -a;
    }
    static int sll (int a, int b) {
        return a << b;
    }
    static int srl (int a, int b) {
        return a >> b;
    }
    static int sru (int a, int b) {
        return a >>> b;
    }
    static int and(int a, int b) {
        return a & b;
    }
    static int or(int a, int b) {
        return a | b;
    }
    static int xor(int a, int b) {
        return a ^ b;
    }
    static int not(int a) {
        return ~a;
    }
    static int inc(int a) {
        return ++a;
    }
    static int dec(int a) {
        return --a;
    }
}