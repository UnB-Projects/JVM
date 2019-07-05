public class Lookupswitch {
    public static void main(String[] args) {
        lookupswitch1(0);
        lookupswitch1(5);
        lookupswitch1(1231231);
        lookupswitch2(1);
    }

    static void lookupswitch2(int i) {
        switch (i) {
        case 1:
            System.out.println("1");
            i = 2;
        case 2:
            System.out.println("2");
            i = 3;
        case 3:
            System.out.println("3");
            i = 4;
        case 4:
            System.out.println("4");
        case 5:
            System.out.println("5");
        case 6:
            System.out.println("6");
        case 7:
            System.out.println("7");
        case 8:
            System.out.println("8");
        case 1231231:
            System.out.println("9");
        default:
            System.out.println("10");
        }
    }

    static void lookupswitch1(int i) {
        switch (i) {
        case 1:
            System.out.println("1");
            break;
        case 2:
            System.out.println("2");
            break;
        case 3:
            System.out.println("3");
            break;
        case 4:
            System.out.println("4");
            break;
        case 5:
            System.out.println("5");
            break;
        case 6:
            System.out.println("6");
            break;
        case 7:
            System.out.println("7");
            break;
        case 8:
            System.out.println("8");
            break;
        case 1231231:
            System.out.println("9");
            break;
        default:
            System.out.println("10");
            break;
        }
    }
}