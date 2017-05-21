import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Locale;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		int n;
		Scanner cin=new Scanner(System.in);
		SimpleDateFormat df=new SimpleDateFormat("yyyy-MM-dd EEEE",Locale.US);
		while(cin.hasNext()){
		    n=cin.nextInt();
		    if(n==-1)break;
			GregorianCalendar wt=new GregorianCalendar(2000,Calendar.JANUARY,1);
			wt.add(GregorianCalendar.DATE, n);
			Date d=wt.getTime();
		    System.out.println(df.format(d));
		}
	}
}
