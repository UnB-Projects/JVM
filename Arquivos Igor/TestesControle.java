class TestesControle {
    public static void main(String[] args) {
        System.out.println("if_cmp");
        if_icmp();
        System.out.println("\nif_zero");
        if_zero();
        System.out.println("\nifnull");
        ifnull();
        System.out.println("\ncmp");
        cmp();
    }

    static void cmp() {
        long a = 1;
        long b = 2;

        boolean c = a == b;
        System.out.println(c);
        c = a < b;
        System.out.println(c);
        c = a > b;
        System.out.println(c);

        float d = 2.5f;
        float e = -2.7f;

        boolean f = d < e;
        System.out.println(f);
        f = d > e;
        System.out.println(f);

        double g = 2.5;
        double h = -2.7;

        boolean i = g < h;
        System.out.println(i);
        i = g > h;
        System.out.println(i);
    }

    static void ifnull() {
        String a = null;
        String b = "ola jovem";

        if (a == null) {
            System.out.println("a == null");
        }
        if (a != null) {
            System.out.println(a);
        }
        if (b == null) {
            System.out.println("b == null");
        }
        if (b != null) {
            System.out.println(b);
        }


    }
    static void if_zero() {
        int a = 0;
        int b = 1;
        int c = -1;

        if (a == 0) {
            System.out.println("a == 0");
        }
        if (a != 0) {
            System.out.println("a != 0");
        }
        if (a < 0) {
            System.out.println("a < 0");
        }
        if (a <= 0) {
            System.out.println("a <= 0");
        }
        if (a > 0) {
            System.out.println("a > 0");
        }
        if (a >= 0) {
            System.out.println("a >= 0");
        }
        if (b == 0) {
            System.out.println("b == 0");
        }
        if (b != 0) {
            System.out.println("b != 0");
        }
        if (b < 0) {
            System.out.println("b < 0");
        }
        if (b <= 0) {
            System.out.println("b <= 0");
        }
        if (b > 0) {
            System.out.println("b > 0");
        }
        if (b >= 0) {
            System.out.println("b >= 0");
        }
        if (c == 0) {
            System.out.println("c == 0");
        }
        if (c != 0) {
            System.out.println("c != 0");
        }
        if (c < 0) {
            System.out.println("c < 0");
        }
        if (c <= 0) {
            System.out.println("c <= 0");
        }
        if (c > 0) {
            System.out.println("c > 0");
        }
        if (c >= 0) {
            System.out.println("c >= 0");
        }
    }

    static void if_icmp() {
        int a = 1;
        int b = 1;
        int c = 2;
        int d = 0;

        if (a == b) {
            System.out.println("a == 1");
        }
        else {
            System.out.println("a != 1");
        }
        if (a == b) {
            System.out.println("a == b");
        }
        if (a != b) {
            System.out.println("a != b");
        }
        if (a < b) {
            System.out.println("a < b");
        }
        if (a <= b) {
            System.out.println("a <= b");
        }
        if (a > b) {
            System.out.println("a > b");
        }
        if (a >= b) {
            System.out.println("a >= b");
        }
        if (a == c) {
            System.out.println("a == c");
        }
        if (a != c) {
            System.out.println("a != c");
        }
        if (a < c) {
            System.out.println("a < c");
        }
        if (a <= c) {
            System.out.println("a <= c");
        }
        if (a > c) {
            System.out.println("a > c");
        }
        if (a >= c) {
            System.out.println("a >= c");
        }
        if (a == d) {
            System.out.println("a == d");
        }
        if (a != d) {
            System.out.println("a != d");
        }
        if (a < d) {
            System.out.println("a < d");
        }
        if (a <= d) {
            System.out.println("a <= d");
        }
        if (a > d) {
            System.out.println("a > d");
        }
        if (a >= d) {
            System.out.println("a >= d");
        }
    }
}