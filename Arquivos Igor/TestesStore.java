class TestesStore {
    public static void main(String[] args) {
        istore();
        lstore();
        fstore();
        dstore();
    }

    static void istore() {
        int ia = 1;
        int ib = 2;
        int ic = 3;
        int id = 4;
        int ie = 5;
        System.out.println(ia);
        System.out.println(ib);
        System.out.println(ic);
        System.out.println(id);
        System.out.println(ie);
    }

    static void lstore() {
        long la = 10000000000l;
        long lb = 20000000000l;
        long lc = 30000000000l;
        long ld = 40000000000l;
        long le = 50000000000l;
        System.out.println(la);
        System.out.println(lb);
        System.out.println(lc);
        System.out.println(ld);
        System.out.println(le);
    }

    static void fstore() {
        float fa = 1.1f;
        float fb = 2.2f;
        float fc = 3.3f;
        float fd = 4.4f;
        float fe = 5.5f;
        System.out.println(fa);
        System.out.println(fb);
        System.out.println(fc);
        System.out.println(fd);
        System.out.println(fe);
    }

    static void dstore() {
        double da = 1.1000001;
        double db = 2.2000001;
        double dc = 3.3000001;
        double dd = 4.4000001;
        double de = 5.5000001;
        System.out.println(da);
        System.out.println(db);
        System.out.println(dc);
        System.out.println(dd);
        System.out.println(de);
    }
}