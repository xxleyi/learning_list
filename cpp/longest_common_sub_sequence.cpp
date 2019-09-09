#include<iostream>

using namespace std;

int lcs_sub_seq(char *m, char *n, int l_m, int l_n)
{
    int t[l_m + 1][l_n + 1];
    for (int i = 0; i <= l_m; i++)
    {
        for (int j = 0; j <= l_n; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (m[i - 1] == m[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[l_m][l_n];
}

int main(int argc, char const *argv[])
{
    char m[] = "liuximin";
    char n[] = "liuaximin";
    cout << "Length of longest common sub sequence is "
         << lcs_sub_seq(m, n, strlen(m), strlen(n)) << endl;
    return 0;
}
