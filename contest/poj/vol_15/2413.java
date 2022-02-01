

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		int cnt;
		BigInteger a,b;
		BigInteger fibs[]=new BigInteger[1000];
		Scanner cin=new Scanner(System.in);
		fibs[0]=BigInteger.ONE;
		fibs[1]=BigInteger.ONE;
		for(int i=2;i<1000;i++){
			fibs[i]=fibs[i-2].add(fibs[i-1]);
		}
		while(cin.hasNext()){
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ZERO)==0)break;
			cnt=0;
			for(int i=1;i<1000;i++){
			    if(fibs[i].compareTo(a)>=0 && fibs[i].compareTo(b)<=0)cnt++;
			    if(fibs[i].compareTo(b)>0)break;
			}
			System.out.println(cnt);
		}
	}
}
