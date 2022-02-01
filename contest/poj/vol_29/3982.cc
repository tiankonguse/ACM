import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        BigInteger[] a=new BigInteger[100];
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            a[0]=cin.nextBigInteger();
            a[1]=cin.nextBigInteger();
            a[2]=cin.nextBigInteger();
            for(int i=3;i<100;i++){
                a[i]=a[i-3].add(a[i-2]).add(a[i-1]);
            }
            System.out.println(a[99]);
        }
    }

}
