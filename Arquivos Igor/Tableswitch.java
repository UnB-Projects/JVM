public class Tableswitch {
    public static void main(String[] args) {
        tableswitch1(0);
        tableswitch1(5);
        tableswitch1(1231231);
        tableswitch2(1);
    }

    static void tableswitch2(int i) {
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
        case 10:
            System.out.println("9");
        default:
            System.out.println("10");
        }
    }

    static void tableswitch1(int i) {
        switch (i) {
        case 5:
            System.out.println("1");
            break;
        case 6:
            System.out.println("2");
            break;
        case 7:
            System.out.println("3");
            break;
        case 8:
            System.out.println("4");
            break;
        case 9:
            System.out.println("5");
            break;
        case 10:
            System.out.println("6");
            break;
        case 11:
            System.out.println("7");
            break;
        case 12:
            System.out.println("8");
            break;
        case 13:
            System.out.println("9");
            break;
        default:
            System.out.println("10");
            break;
        }
    }
}