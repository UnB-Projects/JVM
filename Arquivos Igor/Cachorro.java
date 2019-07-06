class Cachorro extends Animal {
    private int raca;
    public Coleira coleira;

    Cachorro() {
        coleira = new Coleira();
    }

    public void andar() {
        System.out.println("Cachorro esta andando");
    }
}