class StaticClass {
    public static long longNumber = 10;
    public static int[] arrayint = {1,2,3};

    static long returnLongNumber() {
        return longNumber++;
    }

    static void printArrayInt() {
        for (int i = 0; i < 3; i++) {
            System.out.println(arrayint[i]);
        }
    }
}