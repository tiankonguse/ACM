

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		BigInteger a;
		int b;
		while(cin.hasNext()){
			a=cin.nextBigInteger();
			b=cin.nextInt();
			if(a.compareTo(BigInteger.ZERO)==0 && b==0)break;
			System.out.println(a.pow(b));
		}
	}
}
