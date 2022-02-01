import java.math.BigInteger;
import java.util.Scanner;


public class Solution {

    static BigInteger C[][];
    static BigInteger D[];
    static BigInteger A[];
    public static void main(String[] args) {
       C = new BigInteger[105][105];
       D = new BigInteger[105];
       A = new BigInteger[105];
       A[0] = BigInteger.ONE;
       for (int i = 1; i <= 100; ++i) A[i] = A[i - 1].multiply(BigInteger.valueOf(i));
       for (int i = 0; i <= 100; ++i) {
           for (int j = 0; j <= 100; ++j) {
               C[i][j] = BigInteger.ZERO;
           }
       }
       C[0][0] = BigInteger.ONE;
       
       for (int i = 1; i <= 100; ++i) {
           C[i][0] = BigInteger.ONE;
           for (int j = 1; j <= 100; ++j) {
               C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
           }
       }
       D[0] = BigInteger.ONE; D[1] = BigInteger.ZERO;
       for (int i = 2; i <= 100; ++i) {
           D[i] = (D[i - 1].add(D[i - 2])).multiply(BigInteger.valueOf(i - 1));
       }
       int K, N;
       Scanner cin = new Scanner(System.in);
       while (cin.hasNextInt()) {
           K = cin.nextInt();
           N = cin.nextInt();
           if (K + 1 == N) {
               System.out.println(0);
               continue;
           }
           BigInteger a = C[N][K].multiply(D[N - K]);
           BigInteger b = A[N];
           BigInteger g = a.gcd(b);
           a = a.divide(g);
           b = b.divide(g);
           System.out.println(a + "/" + b);
       }
       
    }
}

