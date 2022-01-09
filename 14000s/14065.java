import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double f = sc.nextDouble();
        System.out.printf("%.6f", 100.0/(f*1.609344/3.785411784));
    }
}
