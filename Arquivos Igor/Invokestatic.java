class Invokestatic {
    public static void main(String[] args) {
        System.out.println("Testes int");
        System.out.println(somaInt(1, 2));
        System.out.println(subInt(1, 2));
        System.out.println(divInt(4, 2));
        System.out.println(divInt(6, 2));
        System.out.println(divInt(3, 2));
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

        System.out.println("\nTestes long");
        System.out.println(ladd(2000000000l, 2123456789l));
        System.out.println(lsub(7000000000l, 2123456789l));
        System.out.println(lsub(7000000000l, -2123456789l));
        System.out.println(lmul(2000000000l,2000000000l));
        System.out.println(lmul(2000000000l,-2000000000l));
        System.out.println(ldiv(2000000000l, 2l));
        System.out.println(ldiv(2000000000l, -2l));
        System.out.println(lmod(2l, 1l));
        System.out.println(lmod(3l, 2l));
        System.out.println(lmod(-3l, 2l));
        System.out.println(lmod(-3l, -2l));
        System.out.println(lneg(7l));
        System.out.println(lsll(2l, 4l));
        System.out.println(lsrl(32l, 4l));
        System.out.println(lsru(-32l, 4l));
        System.out.println(land(3l, 5l));
        System.out.println(lor(3l, 5l));
        System.out.println(lxor(3l, 5l));
        System.out.println(lnot(3l));

        System.out.println("\nTestes float");
        System.out.println(fadd(2.31f, 2.61f));
        System.out.println(fadd(2.31f, 2.61f));
        System.out.println(fsub(2.31f, 2.61f));
        System.out.println(fmul(2.31f, 2.61f));
        System.out.println(fdiv(2.31f, 2.61f));
        System.out.println(fmod(2.31f, 2.61f));
        System.out.println(fmod(4.0f, 2.0f));
        System.out.println(fneg(2.31f));
        System.out.println(fneg(0.0f));
        System.out.println(fneg(-0.0f));

        System.out.println("\nTestes double");
        System.out.println(dadd(2.31, 2.61));
        System.out.println(dadd(2.31, 2.61));
        System.out.println(dsub(2.31, 2.61));
        System.out.println(dmul(2.31, 2.61));
        System.out.println(ddiv(2.31, 2.61));
        System.out.println(dmod(2.31, 2.61));
        System.out.println(dmod(4.0, 2.0));
        System.out.println(dneg(2.31));
        System.out.println(dneg(0.0));
        System.out.println(dneg(-0.0));

        retornoVazio();

        System.out.println("\nTestes conversoes");
        System.out.println(i2l(10));
        System.out.println(i2l(-10));
        System.out.println(i2f(10));
        System.out.println(i2f(-10));
        System.out.println(i2d(10));
        System.out.println(i2d(-10));
        System.out.println(i2b(10));
        System.out.println(i2b(-10));
        System.out.println(i2b(300));
        System.out.println(i2s(50000));
        System.out.println(i2s(-10));
        System.out.println(i2c(90));
        System.out.println(i2c(70));
    };

    static void retornoVazio() {
        System.out.println("Esse método tem retorno void");
        return;
    }

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

    static long ladd(long a, long b) {
        return a+b;
    }
    static long lsub(long a, long b) {
        return a-b;
    }
    static long lmul(long a, long b) {
        return a*b;
    }
    static long ldiv(long a, long b) {
        return a/b;
    }
    static long lmod(long a, long b) {
        return a % b;
    }
    static long lneg (long a) {
        return -a;
    }
    static long lsll (long a, long b) {
        return a << b;
    }
    static long lsrl (long a, long b) {
        return a >> b;
    }
    static long lsru (long a, long b) {
        return a >>> b;
    }
    static long land(long a, long b) {
        return a & b;
    }
    static long lor(long a, long b) {
        return a | b;
    }
    static long lxor(long a, long b) {
        return a ^ b;
    }
    static long lnot(long a) {
        return ~a;
    }

    static float fadd(float a, float b) {
        return a+b;
    }
    static float fsub(float a, float b) {
        return a-b;
    }
    static float fmul(float a, float b) {
        return a*b;
    }
    static float fdiv(float a, float b) {
        return a/b;
    }
    static float fmod(float a, float b) {
        return a % b;
    }
    static float fneg (float a) {
        return -a;
    }

    static double dadd(double a, double b) {
        return a+b;
    }
    static double dsub(double a, double b) {
        return a-b;
    }
    static double dmul(double a, double b) {
        return a*b;
    }
    static double ddiv(double a, double b) {
        return a/b;
    }
    static double dmod(double a, double b) {
        return a % b;
    }
    static double dneg (double a) {
        return -a;
    }

    static long i2l(int a) {
        return (long)a;
    }
    static float i2f(int a) {
        return (float)a;
    }
    static double i2d(int a) {
        return (double)a;
    }
    static byte i2b(int a) {
        return (byte)a;
    }
    static short i2s(int a) {
        return (short)a;
    }
    static char i2c(int a) {
        return (char)a;
    }
}