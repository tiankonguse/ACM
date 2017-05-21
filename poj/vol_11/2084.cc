import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        BigInteger[] ctl=new BigInteger[101];
        ctl[0]=new BigInteger("1");
        ctl[1]=new BigInteger("1");
        for(int i=2;i<=100;i++){
            ctl[i]=new BigInteger("0");
            for(int j=0;j<i;j++){
                ctl[i]=ctl[i].add(ctl[j].multiply(ctl[i-j-1]));
            }
        }
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            int N=cin.nextInt();
            if(N==-1)break;
            System.out.println(ctl[N]);
        }
        
    }
}
