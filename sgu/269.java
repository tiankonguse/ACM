import java.util.Arrays;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
	    int i , j , n , K;
	    n = cin.nextInt();
	    K = cin.nextInt();
	    int a[] = new int[n + 1];
	    for (i = 1 ; i <= n ; ++ i)
	    	a[i] = cin.nextInt();
	    Arrays.sort(a , 1 , n + 1);
	    BigInteger f[][] = new BigInteger[n + 5][K + 5];
	    for (i = 0 ; i < n + 5 ; ++ i)
	    	for (j = 0 ; j < K + 5 ; ++ j)
	    		f[i][j] = BigInteger.ZERO;
	    f[0][0] = BigInteger.ONE;
	    for (i = 1 ; i <= n ; ++ i)
	        for (j = 0 ; j <= K ; ++ j)
	        {
	            f[i][j] = f[i][j].add(f[i - 1][j]);
	            if (j != 0)
	                f[i][j] = f[i][j].add(f[i - 1][j - 1].multiply(BigInteger.valueOf(a[i] - j + 1)));
	        }
	    System.out.println(f[n][K]);
	}
}

