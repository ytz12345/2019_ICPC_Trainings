import java.util.*;
import java.math.*;

public class Main{
    static class Fraction { 
        public BigInteger x, y;
        public Fraction(BigInteger x, BigInteger y) {
            this.x = x; this.y = y; }
        public Fraction(int x, int y) {
			this.x = BigInteger.valueOf(x);
			this.y = BigInteger.valueOf(y); }
		public Fraction add(Fraction b) {
			return  new Fraction(x.multiply(b.y).add(y.multiply(b.x)), y.multiply(b.y)).normal(); }
        public Fraction sub(Fraction b) {
            return new Fraction(x.multiply(b.y).subtract(y.multiply(b.x)), y.multiply(b.y)).normal(); }
        public Fraction mul(Fraction b) {
            return new Fraction(x.multiply(b.x), y.multiply(b.y)).normal(); }
        public Fraction div(Fraction b) {
            return new Fraction(x.multiply(b.y), y.multiply(b.x)).normal(); }
        public boolean isZero() {
            return x.equals(BigInteger.ZERO); }
        public Fraction normal() {
            BigInteger gcd = x.gcd(y);
            return new Fraction(x.divide(gcd), y.divide(gcd)); }
    }

    static int n;
    static final int N = 100510;
    static int[] xx = new int[N];
    static int[] yy = new int[N];
    static Fraction[] px = new Fraction[N];
    static Fraction[] py = new Fraction[N];
    static Fraction[] vk = new Fraction[N];
    static Fraction[] vv = new Fraction[N];
    static final Fraction two = new Fraction(2, 1);
    
    static boolean check(Fraction k, Fraction b, Fraction x, Fraction y) {
        return y.sub(k.mul(x).add(b)).isZero();
    }

    static int check() {
        Fraction sumk = new Fraction(0, 1);
        Fraction sumb = new Fraction(0, 1);
        for (int i = 2; i < n; i ++) sumb = sumb.add(vv[i - 1].mul(px[i]));
        for (int i = 2; i < n; i ++) sumk = sumk.sub(vv[i - 1]);
        for (int i = 1; i <= n; i ++) {
            if (!check(sumk,sumb,px[i],py[i])) return 0;
            if (i>1 && i<n) {
                sumb=sumb.sub(vv[i-1].mul(px[i]).mul(two));
                sumk=sumk.add(vv[i-1].mul(two));
            }
        }
        return 1;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt(); n += 1;
        for (int i = 1; i <= n; i ++) {
            xx[i] = cin.nextInt();
            yy[i] = cin.nextInt();
            px[i] = new Fraction(xx[i], 1);
            py[i] = new Fraction(yy[i], 1);
            if (i > 1) vk[i - 1] = new Fraction((yy[i]-yy[i-1]), (xx[i]-xx[i-1]));
        }
        Fraction sum = new Fraction(0, 1);
        for (int i = 2; i < n; i ++) {
            vv[i - 1] = vk[i].sub(vk[i - 1]).div(two);
            sum = sum.add(vv[i - 1]);
        }
        if ((sum.add(vk[1])).isZero() == true && check() == 1) System.out.println("Yes");
        else System.out.println("No");
    }
}
/*
2
-1 2
1 0
2 1 

3
-3 -1
-1 -1
1 1
4 1

3
-3 1
-2 0
0 1
1 1

*/
