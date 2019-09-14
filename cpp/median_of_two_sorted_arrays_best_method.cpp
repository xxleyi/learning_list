#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
private:
inline int safe_get(vector<int> & v, int idx) {
    if (idx < 0)
        return INT_MIN;
    else if (idx >= v.size())
        return INT_MAX;
    else
        return v[idx];
}
public:
    double find_median_sorted_arrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int lo = 0, hi = m, after = (m + n + 1) / 2, pa;
        while (lo < hi) {
            pa = lo + (hi - lo) / 2;
            a[pa] >= safe_get(b, after - pa - 1) ? hi = pa : lo = pa + 1;
        }
        pa = lo;
        int pb = after - lo;
        double max_left = max(safe_get(a, pa - 1), safe_get(b, pb - 1));
        double min_right = min(safe_get(a, pa), safe_get(b, pb));
        return (m + n) % 2 ? max_left : (max_left + min_right) / 2;
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