class Multi {
    public static void main(String[] args) {
        // int[][] array1 = new int[5][5];
        int[][][] array2 = new int[5][4][3];
        // double[][] array3 = new double[4][3];
        // for (int i = 0; i < 5; i++) {
        //     for (int j = 0; j < 5; j++) {
        //         array1[i][j] = 3;
        //     }
        // }

        // for (int i = 0; i < 5; i++) {
        //     for (int j = 0; j < 5; j++) {
        //         System.out.println(array1[i][j]);
        //     }
        // }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 3; k++) {
                    array2[i][j][k] = 2;
                }
            }
        }
    }
}