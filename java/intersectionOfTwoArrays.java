import java.io.*;
import java.util.*;

class Solution {
    public int[] intersect(int[] a, int[] b) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> tempRes = new ArrayList<Integer>();
        for (int i : a)
            map.put(i, map.getOrDefault(i, 0) + 1);
        for (int i : b) {
            if (map.getOrDefault(i, 0) > 0) {
                tempRes.add(i);
                map.put(i, map.get(i) - 1);
            }
        }
        int[] res = new int[tempRes.size()];
        for (int i = 0; i < tempRes.size(); i++) 
            res[i] = tempRes.get(i);

        return res;
    }

    public static void main(String[] args) {
        int a[] = { 1, 6, 2, 3, 4, 5, };
        int b[] = { 3, 4, 5, 6, };
        Solution s = new Solution();
        for (int i : s.intersect(a, b))
            System.out.println(i);
    }
}