class Solution {
    private int safeGet(int[] v, int idx) {
        if (idx < 0)
            return Integer.MIN_VALUE;
        if (idx >= v.length)
            return Integer.MAX_VALUE;
        return v[idx];
    }

    public double findMedianSortedArrays(int[] a, int[] b) {
        int m = a.length, n = b.length;
        int lo = 0, hi = m, after = (m + n + 1) / 2, pa;
        while (lo < hi) {
            pa = lo + (hi - lo) / 2;
            if (a[pa] >= this.safeGet(b, after - pa - 1))
                hi = pa;
            else
                lo = pa + 1;
        }
        pa = lo;
        int pb = after - pa;
        double maxLeft = Math.max(this.safeGet(a, pa - 1), this.safeGet(b, pb - 1));
        double minRight = Math.min(this.safeGet(a, pa), this.safeGet(b, pb));
        return (m + n) % 2 == 1 ? maxLeft : (maxLeft + minRight) / 2;
    }
    
    public static void main(String[] args) {
        int a[] = { 1, 2, 3, 4, 5, };
        int b[] = { 3, 4, 5, 6, };
        Solution s = new Solution();
        System.out.println(s.findMedianSortedArrays(a, b));
    }
}