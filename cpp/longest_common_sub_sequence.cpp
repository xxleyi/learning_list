#include<iostream>

using namespace std;

int lcs_sub_seq(const char a[], const char b[], const int m, const int n)
{
    int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[m][n];
}

int main(int argc, char const *argv[])
{
    char a[] = "liuximin";
    char b[] = "liuaximin";
    cout << "Length of longest common sub sequence is "
         << lcs_sub_seq(a, b, strlen(a), strlen(b)) << endl;
    return 0;
}
