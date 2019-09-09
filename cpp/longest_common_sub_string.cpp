#include <iostream>

using namespace std;

int lcs_sub_str(char *m, char *n, int l_m, int l_n)
{
    int t[l_m + 1][l_n + 1];
    int max_len = 0;
    for (int i = 0; i <= l_m; i++)
    {
        for (int j = 0; j <= l_n; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (m[i - 1] == n[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
                if (t[i - 1][j - 1] == max_len)
                    max_len++;
            }
            else
                t[i][j] = 0;
        }
    }
    return max_len;
}

int main(int argc, char const *argv[])
{
    char m[] = "liuximin";
    char n[] = "liuaximin";
    cout << "Length of longest common sub string is " 
         << lcs_sub_str(m, n, strlen(m), strlen(n)) << endl;
    return 0;
}
