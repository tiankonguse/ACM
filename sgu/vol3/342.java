import java.util.Scanner;
import java.math.BigInteger;
/**
 *
 * @author vici
 */
public class Solution {

    public static void main(String[] args) {
       Scanner cin = new Scanner(System.in);
       BigInteger A, B;
       A = cin.nextBigInteger();
       B = cin.nextBigInteger();
       long b = B.longValue();
       if (b == 1) {
           System.out.println(A);
           return;
       }
       long S[] = new long[10010];
       int cnt = 0;
       while (A.compareTo(BigInteger.ZERO) != 0) {
           S[cnt++] = A.mod(B).longValue();
           A = A.divide(B);
       }
       long dp[][] = new long[10010][2];
       dp[0][0] = S[0];
       dp[0][1] = b - S[0];
       for (int i = 1; i < cnt; ++i) {
           dp[i][0] = Math.min(dp[i - 1][0] + S[i], dp[i - 1][1] + S[i] + 1);
           dp[i][1] = Math.min(dp[i - 1][0] + b - S[i], dp[i - 1][1] + b - S[i] - 1);
       }
       long ret = Math.min(dp[cnt - 1][0], dp[cnt - 1][1] + 1);
       System.out.println(ret);
    }
}

