/**
 * @author JKarki
 *
 */
public class Palindrome {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TEST CASES
        String[] testCases = { "Malayalam", "tattarrattat", "hippodrome", " ", "racecar", "computer science" };
        for (String string : testCases) {
            System.out
                    .println(String.format("%s %s palindrome.", string, (isPalindrome(string) ? "is a" : "is not a")));
        }
    }

    public static boolean isPalindrome(String word) {
        // base case: if the length of the word is less than 2 i.e. it is 1 or 0 we know
        // that the word is going to be a palindrome, therefore return true
        if (word.length() < 2)
            return true;
        // general case: convert everything to lowercase first so words like "MalayAlam"
        // will still be considered a palindrome. Then, first check the first and last
        // character of the current substring and pass the smaller substring without the
        // and the last to recursion to check if it is a palindrome till length < 2
        return Character.toLowerCase(word.charAt(0)) == Character.toLowerCase(word.charAt(word.length() - 1))
                && isPalindrome(word.substring(1, word.length() - 1));
    }

}