import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		BigInteger a;
		BigInteger eps=new BigInteger("1000000000000000000000000000000000000000000000000");
		BigInteger two=new BigInteger("2");
		while(cin.hasNext()){
			a=cin.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO)==0){System.out.println("0 0.0000000000");continue;}
			a=a.multiply(eps);
			BigInteger low=BigInteger.ONE;
			BigInteger high=a;
			BigInteger mid=BigInteger.ZERO;
			while(low.compareTo(high)<=0){
				mid=high.add(low).divide(two);
				if(mid.pow(3).compareTo(a)<=0)low=mid.add(BigInteger.ONE);
				else high=mid.subtract(BigInteger.ONE);
			}
			//low=low.add(new BigInteger("1234"));
			String s=high.toString();
			int slen=s.length()-6;
			int k=0;
			for(int i=0;i<slen;i++){
				if(s.charAt(i)!='.'){
					k+=s.charAt(i)-'0';
				}
			}
			System.out.println(k%10+" "+s.substring(0,slen-10)+"."+s.substring(slen-10,slen));
		}
	}
}

