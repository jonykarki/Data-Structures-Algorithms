public class GCD {
    public static void main(String[] args) {
        // TEST CASES
        int[][] testCases = { { 36, 20 }, { 0, 0 }, { 13978, 15457 }, { 100, 44 }, { 69, 27 } };
        for (int[] testCase : testCases) {
            System.out.println(
                    String.format("GCD of %d and %d is %d.", testCase[0], testCase[1], gcd(testCase[0], testCase[1])));
        }
    }

    public static int gcd(int a, int b) {
        // the base case since gcd(x, 0) = |x|, for x != 0
        if (b == 0)
            return a;
        // the general case where b is not 0 hence, we continue reduction and
        // calculate the gcd of b and and the remainder of a divided by b
        return gcd(b, a % b);
    }
}
