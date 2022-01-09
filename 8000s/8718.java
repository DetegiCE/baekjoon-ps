import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        x *= 1000;
        int k = sc.nextInt();
        if(x >= k * 7000) System.out.println(k*7000);
        else if(x >= k * 3500) System.out.println(k*3500);
        else if(x >= k * 1750) System.out.println(k*1750);
        else System.out.println(0);
    }
}
