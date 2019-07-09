class TestesArray {
    public static void main(String[] args) {
       criacao_arrays();
       multianewarray();
    }

    static void multianewarray() {
        int[][] a;
        int[][] b = {{1,2,3}, {4,5,6}, {7,8,9}};

        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                System.out.println(b[i][j]);
            }
        }
    }
    static void criacao_arrays() {
        int[] a;
        int[] b = {1,2,3,4,5,6,7,8,9,10};
        boolean[] c = {true,false,true,false,true,false,true,false,true,false};
        byte[] d = {1,2,3,4,5,6,7,8,9,10};
        short[] e = {1,2,3,4,5,6,7,8,9,10};
        long[] f = {10000000000l,20000000000l,30000000000l,40000000000l,50000000000l,60000000000l,70000000000l,80000000000l,90000000000l,100000000000l};
        float[] g = {1.1f,2.2f,3.3f,4.4f,5.5f,6.6f,7.7f,8.8f,9.9f,10.0f};
        double[] h = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.0};
        char[] j = {'a','b','c','d','e','f','g','h','i','j'};


        for (int i = 0; i < 10; i++) {
            System.out.println(b[i]);
            System.out.println(c[i]);
            System.out.println(d[i]);
            System.out.println(e[i]);
            System.out.println(f[i]);
            System.out.println(g[i]);
            System.out.println(h[i]);
            System.out.println(j[i]);
        }
    }
}