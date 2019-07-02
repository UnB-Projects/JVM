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
}