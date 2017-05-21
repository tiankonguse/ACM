
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[]args){
		BigInteger dat[]=new BigInteger[100];
		dat[0]=BigInteger.ONE;
		BigInteger tr=new BigInteger("3");
		for(int i=1;i<100;i++){
			dat[i]=dat[i-1].multiply(tr);
		}
		long N;
		int t;
		boolean first;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			N=cin.nextLong();
			if(N==0)break;
			N--;
			t=0;
			first=true;
			System.out.print("{");
			while(N>0){
				if(N%2==1){
					if(first){
						first=false;
						System.out.print(" "+dat[t]);
					}
					else System.out.print(", "+dat[t]);
				}
				t++;
				N/=2;
			}
			System.out.println(" }");
		}
	}
}
