class Cachorro extends Animal {
    private int raca;
    public Coleira coleira;

    Cachorro() {
        coleira = new Coleira();
        raca = 3;
    }

    public void andar() {
        System.out.println("Cachorro esta andando");
    }
}