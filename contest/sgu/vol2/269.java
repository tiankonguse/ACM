
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author vici
 */
public class Solution{

    static BigInteger dp[][];
    public static void main(String[] args) {
       dp = new BigInteger[255][255];
       Scanner cin = new Scanner(System.in);
       int n, k;
       n = cin.nextInt();
       k = cin.nextInt();
       int arr[] = new int[n];
       for (int i = 0; i < n; ++i) {
           arr[i] = cin.nextInt();
       }
       Arrays.sort(arr);
       
       for (int i = 0; i < 255; ++i) {
           for (int j = 0; j < 255; ++j) {
               dp[i][j] = BigInteger.ZERO;
           }
       }
       dp[0][0] = BigInteger.ONE;
       dp[0][1] = BigInteger.valueOf(arr[0]);
       for (int i = 1; i < n; ++i) {
           dp[i][0] = BigInteger.ONE;
           for (int j = 1; j <= i + 1; ++j) {
               dp[i][j] = dp[i - 1][j].add(dp[i - 1][j - 1].multiply(BigInteger.valueOf(arr[i] - j + 1)));
           }
       }
       System.out.println(dp[n - 1][k]);
    }
}
