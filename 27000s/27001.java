import java.util.*;
import java.time.*;
import java.time.format.*;

public class Main {
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    
	    int y = sc.nextInt();
	    int m = sc.nextInt();
	    int d = sc.nextInt();
	    LocalDate dt = LocalDate.of(y, m, d);
	    DayOfWeek dw = dt.getDayOfWeek();
	    System.out.println(dw.getDisplayName(TextStyle.FULL, Locale.US).toLowerCase());
	}
}
