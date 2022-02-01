import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author vici
 */
public class Solution{

    public static void main(String[] args) {
        BigInteger a, b, n, t;
        Scanner cin = new Scanner(System.in);
        int m;
        n = cin.nextBigInteger();
        m = cin.nextInt();
        if (m == 0) {
            System.out.println(1);
        }
        else {
            a = BigInteger.ZERO;
            b = BigInteger.ONE;
            for (int i = 1; i < m; ++i) {
                t = a;
                a = b.multiply(n);
                b = t.add(b.add(b));
            }
            System.out.println(a);
        }
    }
}
