import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Example 1:

// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:

// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

class Solution {
    public void setZeroes(int[][] matrix) {
        boolean firstColIsZero = false;
        int rowLen = matrix.length, colLen = matrix[0].length;
        for (int i = 0; i < rowLen; i++) {
            if (matrix[i][0] == 0)
                firstColIsZero = true;
            for (int j = 1; j < colLen; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rowLen; i++) {
            for (int j = 1; j < colLen; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 1; j < colLen; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColIsZero) {
            for (int i = 0; i < rowLen; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = { { 0, 1, 2, 0 }, { 1, 3, 1, 5 }, { 3, 4, 5, 2 } };
        Solution s = new Solution();
        s.setZeroes(matrix);
        for (int[] row : matrix) {
            List<Integer> temp = new ArrayList<Integer>();
            for (int e : row)
                temp.add(e);
            System.out.println(temp);
        }
    }
}