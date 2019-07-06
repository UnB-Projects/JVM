class MundoAnimal {
    public static void main(String[] args) {
        Cachorro c1 = new Cachorro();
        c1.andar();
        System.out.println(c1.coleira.nome);
        System.out.println(c1.coleira.num);

        Animal a1 = new Animal();
        a1.andar();

        Animal c2 = new Cachorro();
        c2.andar();
    }
}