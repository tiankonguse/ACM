import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int t=cin.nextInt();
		String s1,s2;
		BigInteger a,b;
		for(int i=0;i<t;i++){
			s1=cin.next();
			s2=cin.next();
			if(s1.charAt(0)=='+'){
				s1=s1.substring(1);
			}
			if(s2.charAt(0)=='+'){
				s2=s2.substring(1);
			}
			a=new BigInteger(s1);
			b=new BigInteger(s2);
			System.out.println(a.add(b));
		}
	}
}
