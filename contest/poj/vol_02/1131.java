import java.math.*;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		BigDecimal a=BigDecimal.ZERO;
		String s;
		int len;
		double d;
		while(cin.hasNext()){
			a=BigDecimal.ZERO;
			s=cin.next();
			len=s.length();
			for(int i=2;i<len;i++){
				a=a.add(BigDecimal.valueOf((s.charAt(i)-'0')).divide(BigDecimal.valueOf(Math.pow(8, i-1))));
				
			}
			System.out.println(s+" [8] = "+a+" [10]");
			
		}
	}
}


