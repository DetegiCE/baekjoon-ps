
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int a[] = new int[26];
        for(int t=0 ; t<n ; t++) {
            String p, q;
            int cnt[][] = new int[2][26];
            String r = sc.nextLine();
            p = r.split(" ")[0];
            q = r.split(" ")[1];
            for(int i=0 ; i<p.length() ; i++)  {
                cnt[0][p.charAt(i) - 'a']++;
            }
            for(int i=0 ; i<q.length() ; i++) {
                cnt[1][q.charAt(i) - 'a']++;
            }
            for(int i=0 ; i<26 ; i++) {
                a[i] += cnt[0][i] > cnt[1][i] ? cnt[0][i] : cnt[1][i];
            }
        }
        for(int i=0 ; i<26 ; i++) {
            System.out.println(a[i]);
        }
    }
}
