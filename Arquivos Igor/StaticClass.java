class StaticClass {
    public static long longNumber = 10;

    static long returnLongNumber() {
        return longNumber++;
    }
}