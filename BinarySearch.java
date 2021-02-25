import java.util.Arrays;

public class BinarySearch {

    public static void main(String[] args) {
        // TEST CASES
        int value = 3;
        int[][] arr = { { 1, 2, 2, 3, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 7 },
                { 1, 1, 1, 1, 2, 2, 2, 2, 5, 5, 5, 5, 7, 7, 7, 8, 8, 8, 10, 10, 10, 10, 10 },
                { 12, 15, 15, 15, 15, 16, 16, 16, 16, 17 },
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4 } };
        for (int[] ar : arr) {
            System.out.println(String.format("The first occurence of %d in %s is %d", value, Arrays.toString(ar),
                    findFirstOccurence(ar, 0, ar.length - 1, value, -1)));
        }
    }

    public static int findFirstOccurence(int[] arr, int first, int last, int value, int lowestSoFar) {
        // base case: stop when the first and the last are the same
        if (first == last) {
            // check if the value is at first
            if (arr[first] == value)
                lowestSoFar = first;
            // return the lowestIndex where the value was found or -1 if not found
            return lowestSoFar;
        } else {
            // calculate the mid index
            int mid = first + (last - first) / 2;
            // if the value is found at mid then set lowestSoFar to mid and make a recursive
            // call
            if (value == arr[mid]) {
                return findFirstOccurence(arr, first, mid - 1, value, mid);
            } else if (value < arr[mid]) {
                // look on the lower half
                return findFirstOccurence(arr, first, mid - 1, value, lowestSoFar);
            } else {
                // look on the upper half
                return findFirstOccurence(arr, mid + 1, last, value, lowestSoFar);
            }
        }
    }

}
