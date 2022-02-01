import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		BigInteger a=new BigInteger("1");
		BigInteger c[]=new BigInteger[19];
		for(int i=1;i<=18;i++){
			c[i]=a.add(BigInteger.ONE);
			a=a.multiply(c[i]);
		}
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		for(int i=1;i<=n;i++){
			System.out.println(c[i]);
		}
	}
}
