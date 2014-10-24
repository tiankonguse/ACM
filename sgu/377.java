import java.util.*;
import java.math.*;

public class main {
	public static void main(String[] args) {
    	Scanner cin = new Scanner(System.in);
    	int n , K;
    	K = cin.nextInt();
        n = cin.nextInt() ;
        BigInteger x = BigInteger.ZERO , y;
        y = BigInteger.ONE;
        for (int i = 1 ; i <= n ; ++ i)
        	y = y.multiply(BigInteger.valueOf(2));
        x = x.add(y);
        y = BigInteger.ONE;
        for (int i = 1 ; i <= K ; ++ i)
        	y = y.multiply(BigInteger.valueOf(2));
        x = x.add(y);
        System.out.println(x.subtract(BigInteger.valueOf(2)));
    } 
}
