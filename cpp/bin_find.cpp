#include <iostream>
#include <vector>

using namespace std;

bool bin_find(const int *a, int lo, int hi, const int e)
{
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        e < a[mid] ? hi = mid : lo = mid + 1;
    }
    return lo >= 1 && a[lo - 1] == e;
}

bool bin_find(const vector<int> &a, int lo, int hi, const int e)
{
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        e < a[mid] ? hi = mid : lo = mid + 1;
    }
    return lo >= 1 && a[lo - 1] == e;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    int a_size = sizeof(a) / sizeof(*a);
    cout << "find if 4 in a: "
         << boolalpha
         << bin_find(a, 0, a_size, 4)
         << endl;
    cout << "find if 40 in a: "
         << boolalpha
         << bin_find(a, 0, a_size, 40)
         << endl;
    int b[] = {};
    int b_size = sizeof(b) / sizeof(*b);
    cout << "find if 100 in empty b: "
         << boolalpha
         << bin_find(b, 0, b_size, 100)
         << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(100);
    v.pop_back();
    v.push_back(5);
    cout << "find if 5 in vector v: "
         << boolalpha
         << bin_find(v, 0, v.size(), 5)
         << endl;

    v.clear();
    cout << "find if 5 in empty vector v: "
         << boolalpha
         << bin_find(v, 0, v.size(), 5)
         << endl;

    return 0;
}
