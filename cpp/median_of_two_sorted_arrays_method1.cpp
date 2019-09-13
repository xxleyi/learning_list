#include <iostream>
#include <vector>

using std::vector;

class Solution {
private:
    double find_kth(vector<int> &nums1, int lo1, int hi1, vector<int> &nums2, int lo2, int hi2, int k) {
        if (lo1 > hi1) return nums2[k - lo1];
        if (lo2 > hi2) return nums1[k - lo2];
        int m1 = (lo1 + hi1) / 2;
        int m2 = (lo2 + hi2) / 2;
        if ((m1 + m2) < k){
            // ignore the smaller 1/4
            if (nums1[m1] < nums2[m2])
                // ignore the smaller 1/2 of nums1
                return find_kth(nums1, m1 + 1, hi1, nums2, lo2, hi2, k);
            else
                // ignore the smaller of nums2
                return find_kth(nums1, lo1, hi1, nums2, m2 + 1, hi2, k);
        } else {
            // ignore the bigger 1/4
            if (nums1[m1] > nums2[m2])
                // ignore the bigger 1/2 of nums1
                return find_kth(nums1, lo1, m1 - 1, nums2, lo2, hi2, k);
            else
                // ignore the bigger 1/2 of nums2
                return find_kth(nums1, lo1, hi1, nums2, lo2, m2 - 1, k);
        }
    }
public:
    double find_median_sorted_arrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        double res;
        if ((size_1 + size_2) % 2) {
            int k = (size_1 + size_2) / 2;
            res = find_kth(nums1, 0, size_1 - 1, nums2, 0, size_2 - 1, k);
        } else {
            int k1 = (size_1 + size_2) / 2 - 1;
            int k2 = k1 + 1;
            double mid1 = find_kth(nums1, 0, size_1 - 1, nums2, 0, size_2 - 1, k1);
            double mid2 = find_kth(nums1, 0, size_1 - 1, nums2, 0, size_2 - 1, k2);
            res = (mid1 + mid2) / 2;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    vector<int> nums1{1, 5, 9, 19, 21};
    vector<int> nums2{2, 6, 20, 30, 48};
    Solution s;
    cout << "median is: " << endl;
    cout << s.find_median_sorted_arrays(nums1, nums2) << endl;
    nums2.push_back(50);
    cout << "after push, median is: " << endl;
    cout << s.find_median_sorted_arrays(nums1, nums2) << endl;
    return 0;
}
