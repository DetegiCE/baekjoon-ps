import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lim = sc.nextInt();
        int spd = sc.nextInt();
        int dif = spd - lim;
        if(lim >= spd) {
            System.out.println("Congratulations, you are within the speed limit!");
        }
        else {
            int fine = (dif<=20?100:(dif<=30?270:500));
            System.out.println("You are speeding and your fine is $"+fine+".");
        }
    }
}
