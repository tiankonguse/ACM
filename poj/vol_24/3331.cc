
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		BigInteger fac[]=new BigInteger[501];
		BigInteger f=BigInteger.ONE;
		fac[0]=BigInteger.ONE;
		for(int i=1;i<=500;i++){
			fac[i]=fac[i-1].multiply(f);
			f=f.add(BigInteger.ONE);
		}
		Scanner cin=new Scanner(System.in);
		int T=cin.nextInt();
		int a,b,cnt;
		String s;
		for(int i=0;i<T;i++){
			a=cin.nextInt();
			b=cin.nextInt();
			s=fac[a].toString();
			cnt=0;
			for(int j=0;j<s.length();j++){
				if(s.charAt(j)-'0'==b)cnt++;
			}
			System.out.println(cnt);
		}
	}
}
