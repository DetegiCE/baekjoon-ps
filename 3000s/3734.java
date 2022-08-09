import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger n = sc.nextBigInteger();
        BigInteger k = sc.nextBigInteger();
        BigInteger k2 = k.multiply(BigInteger.valueOf(2));
        for(int i=0 ; i<=100000 ; i++) {
            BigInteger I = BigInteger.valueOf(i);
            BigInteger T = BigInteger.valueOf(i);
            T = T.multiply(T);
            T = T.add(BigInteger.valueOf(4).multiply(k).multiply(n));
            
            
            BigInteger D = T.sqrt();
            if(!D.multiply(D).equals(T)) continue;
            BigInteger p = D.subtract(I);
            if (p.mod(k2).intValue() == 0) {
                p = p.divide(k2);
                BigInteger q = n.divide(p);
                if(!p.equals(BigInteger.ONE) && !q.equals(BigInteger.ONE)) {
                    System.out.println(p + " * " + q);
                    return;
                }
            }
            
            p = D.add(I);
            if (p.mod(k2).intValue() == 0) {
                p = p.divide(k2);
                BigInteger q = n.divide(p);
                if(!p.equals(BigInteger.ONE) && !q.equals(BigInteger.ONE)) {
                    System.out.println(p + " * " + q);
                    return;
                }
            }
        }
    }
}