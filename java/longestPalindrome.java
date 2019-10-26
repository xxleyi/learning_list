// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

class Solution {

    private Boolean isPalindrome(String s, int lo, int hi) {
        while (lo < hi) {
            if (s.charAt(lo) != s.charAt(hi)) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }

    public String longestPalindrome(String s) {
        if (s.length() == 0) {
            return "";
        }
        int start = 0, maxLen = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i - maxLen >= 1 && this.isPalindrome(s, i - maxLen - 1, i)) {
                start = i - maxLen - 1;
                maxLen += 2;
            } else if (i - maxLen >= 0 && this.isPalindrome(s, i - maxLen, i)) {
                start = i - maxLen;
                maxLen += 1;
            }
        }
        return s.substring(start, start + maxLen);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        String str = "话说上海自来水来自海上说话的大爷大妈？";
        System.out.println(s.longestPalindrome(str));
    }
}