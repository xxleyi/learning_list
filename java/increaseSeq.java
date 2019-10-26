// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:

// Return true if there exists i, j, k
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Example 1:

// Input: [1,2,3,4,5]
// Output: true
// Example 2:

// Input: [5,4,3,2,1]
// Output: false

// 下面的解法为通用解法，借助二分查找，查找有序序列长度是否满足，复杂度为 nlogk

class Solution {
    private int bisectLeft(int[] a, int e) {
        int lo = 0, hi = a.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (e <= a[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    public Boolean increaseSeq(int[] nums, int k) {
        int[] seq = new int[k];
        for (int i = 0; i < k; i++) {
            seq[i] = Integer.MAX_VALUE;
        }
        for (int n : nums) {
            int idx = this.bisectLeft(seq, n);
            if (idx >= k - 1) {
                return true;
            }
            seq[idx] = n;
        }
        return false;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = { 1, 2, 3, 2, 1 };
        System.out.println(s.increaseSeq(nums, 4));
        System.out.println(s.increaseSeq(nums, 3));
    }
}