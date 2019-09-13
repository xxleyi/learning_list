#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum(const vector<int> &nums, int target)
{
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur_num = nums[i];
        if (seen.count(cur_num))
            return vector<int>{seen[cur_num], i};
        else
            seen[target - cur_num] = i;
    }
    return vector<int>{};
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 20, 30};
    int target = 31;
    cout << "sum is " << target << ": " << endl;
    for (auto i : two_sum(nums, target))
        cout << i << endl;
    return 0;
}
