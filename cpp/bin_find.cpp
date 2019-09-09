#include<iostream>

using namespace std;

bool bin_find(int a[], int lo, int hi, int e, int mid=0) {
    while (lo < hi) mid = lo + (hi - lo) / 2, e < a[mid] ? hi = mid : lo = mid + 1;
    return lo >= 1 && a[lo - 1] == e;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    cout << "find if 4 in a: "
         << boolalpha
         << bin_find(a, 0, sizeof(a), 4)
         << endl;
    cout << "find if 40 in a: "
         << boolalpha
         << bin_find(a, 0, sizeof(a), 40)
         << endl;
    int b[] = {};
    cout << "find if 100 in empty b: "
         << boolalpha
         << bin_find(b, 0, sizeof(b), 100)
         << endl;

    return 0;
}
