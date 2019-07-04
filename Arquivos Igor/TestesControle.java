class TestesControle {
    public static void main(String[] args) {
        System.out.println("if_cmp");
        if_icmp();
        System.out.println("\nif_zero");
        if_zero();
        System.out.println("\nifnull");
        ifnull();
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