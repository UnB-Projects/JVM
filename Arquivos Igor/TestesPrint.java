class TestesPrint {
    public static void main(String[] args) {
        System.out.println("Println com string hardcoded dentro");
        System.out.println(123);
        System.out.println(5000000000l);
        System.out.println(0.5f);
        System.out.println(0.5d);

        String str = "String instanciada";
        System.out.println(str);

        String str2 = new String("String instanciada com new");
        System.out.println(str2);
    }
}