import java.util.*;

public class Main {
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    char[][] mapp = new char[8][8];
	    for(int i=0 ; i<8 ; i++) {
	        String line = sc.nextLine();
	        for(int j=0 ; j<8 ; j++) {
	            mapp[i][j] = line.charAt(j);
	        }
	    }
	    
	    for(int i=0 ; i<8 ; i++) {
	        for(int j=0 ; j<8 ; j++) {
	            if(mapp[i][j] == 'R') {
	                for(int k=0 ; k<8 ; k++) {
	                    if(mapp[i][k] == '.') mapp[i][k] = 'T';
	                    if(mapp[k][j] == '.') mapp[k][j] = 'T';
	                }
	            }
	        }
	    }
	    
	    int cnt = 0;
	    for(int i=0 ; i<8 ; i++) {
	        for(int j=0 ; j<8 ; j++) {
	            if(mapp[i][j] == '.') {
	                cnt++;
	            }
	        }
	    }
	    
	    System.out.println(cnt);
	}
}
