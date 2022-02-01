import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner cin=new Scanner(System.in);
        BigInteger a=new BigInteger("1");
        BigInteger b=new BigInteger("2");
        BigInteger c=new BigInteger("3");
        BigInteger d;
        int N;
        while(cin.hasNext()){
            N=cin.nextInt();
            if(N%2==1){
                d=b.pow(N-1).subtract(a).divide(c);
            }
            else{
                d=b.pow(N-1).add(a).divide(c);
            }
            System.out.println(d);
        }
    }
}
