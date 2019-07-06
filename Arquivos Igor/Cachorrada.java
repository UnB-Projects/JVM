class Cachorrada {
    public static void main(String[] args) {
        Cachorro c1 = new Cachorro();
        Cachorro c2 = teste(c1);
        Cachorro c3 = new Cachorro();
        c2.raca = 2;
        c2.andar();
        Cachorro[] ca = {c1,c3};
        Cachorro[] ca2 = teste2(ca);
        System.out.println(ca2[0].raca);
    }

    static Cachorro teste(Cachorro c) {
       c.andar();
       return c;
    }

    static Cachorro[] teste2(Cachorro[] c) {
        System.out.println(c[0].raca);
        System.out.println(c[1].raca);
        return c;
    }
}