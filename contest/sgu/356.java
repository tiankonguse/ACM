import java.util.*;
import java.math.*;

public class main {
    
	public static BigInteger gcd(BigInteger A , BigInteger B) {
		if (B == BigInteger.ZERO)
			return A;
		return gcd(B , A.mod(B));
	}
	
	public static void main(String[] args) {
    	Scanner cin = new Scanner(System.in);
    	int n , K;
    	K = cin.nextInt();
        n = cin.nextInt() ;
        BigInteger x , y , z;
        y = BigInteger.ONE;
        for (int i = 1 ; i <= K ; ++ i)
        	y = y.multiply(BigInteger.valueOf(i));
        for (int i = 1 ; i <= n - K ; ++ i)
        	y = y.multiply(BigInteger.valueOf(i));
        x = BigInteger.ONE;
        for (int i = 1 ; i <= n - K ; ++ i) {
        	x = x.multiply(BigInteger.valueOf(i));
            if (i % 2 == 0) {
            	x = x.add(BigInteger.ONE);
            } else {
            	x = x.subtract(BigInteger.ONE);	
            }
        }
        z = gcd(x , y);
        x = x.divide(z);
        y = y.divide(z);
        if (x == BigInteger.ZERO)
        	System.out.println("0");
        else {
        	System.out.println(x + "/" + y);	
        }
    } 
}
