import java.util.Arrays;
import java.util.Scanner;
import java.math.BigInteger;

public class Solution {
	public static void main(String[] args) {
	    Scanner cin = new Scanner(System.in);
	    int i , j , n , K;
	    n = cin.nextInt();
	    K = cin.nextInt();
	    int cnt[] = new int[105];
	    int a[] = new int[105];
	    int b[] = new int[105];
	    for (i = 1 ; i <= n ; ++ i)
	        for (j = 1 ; j <= n ; ++ j)
	            ++ cnt[i + j];
	    
	    int m1 = 0 , m2 = 0;
	    for (i = 2 ; i <= n + n ; ++ i)
	        if ((i & 1) == 0)
	            a[++ m1] = cnt[i];
	        else
	            b[++ m2] = cnt[i];
	    if (K > m1 + m2)
	    {
	        System.out.println("0");
	        return;
	    }
	    Arrays.sort(a , 1 , m1 + 1);
	    Arrays.sort(b , 1 , m2 + 1);
	    BigInteger f[][] = new BigInteger[200][200];
	    for (i = 0 ; i < 200 ; ++ i)
	    	for (j = 0 ; j < 200 ; ++ j)
	    		f[i][j] = BigInteger.ZERO;
	    BigInteger g[][] = new BigInteger[200][200];
	    for (i = 0 ; i < 200 ; ++ i)
	    	for (j = 0 ; j < 200 ; ++ j)
	    		g[i][j] = BigInteger.ZERO;
	    f[0][0] = BigInteger.ONE;
	    for (i = 1 ; i <= m1 ; ++ i)
	        for (j = 0 ; j <= K ; ++ j)
	        {
	            f[i][j] = f[i][j].add(f[i - 1][j]);
	            if (j != 0)
	                f[i][j] = f[i][j].add(f[i - 1][j - 1].multiply(BigInteger.valueOf(a[i] - j + 1)));
	        }
	    g[0][0] = BigInteger.ONE;
	    for (i = 1 ; i <= m2 ; ++ i)
	        for (j = 0 ; j <= K ; ++ j)
	        {
	            g[i][j] = g[i][j].add(g[i - 1][j]);
	            if (j != 0)
	                g[i][j] = g[i][j].add(g[i - 1][j - 1].multiply(BigInteger.valueOf(b[i] - j + 1)));
	        }
	    BigInteger ans = BigInteger.ZERO;
	    for (i = 0 ; i <= K ; ++ i)
	        ans = ans.add(f[m1][i].multiply(g[m2][K - i]));
	    System.out.println(ans);
	}
}

