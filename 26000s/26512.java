import java.util.*;

public class Main
{
    static String right8(String s) {
        String ret = "";
        for(int i=s.length() - 8 ; i<s.length() ; i++) ret += s.charAt(i);
        return ret;
    }
    
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    while(true) {
	        int a = sc.nextInt();
	        int b = sc.nextInt();
	        if(a == 0 && b == 0) break;
	        System.out.println(a + " = " + right8("00000000" + Integer.toBinaryString(a)));
	        System.out.println(b + " = " + right8("00000000" + Integer.toBinaryString(b)));
	        System.out.println(-a + " = " + right8(Integer.toBinaryString(-a)));
	        System.out.println(-b + " = " + right8(Integer.toBinaryString(-b)));
	        System.out.println((a-b) + " = " + right8("00000000" + Integer.toBinaryString(a-b)));
	        System.out.println();
	    }
	}
}
