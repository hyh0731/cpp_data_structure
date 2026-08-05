#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100;
int dp[MAXN][MAXN];

string LCS(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string res;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res += s1[i - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a, b;
    cout << "输入字符串1：";
    cin >> a;
    cout << "输入字符串2：";
    cin >> b;
    string lcs = LCS(a, b);
    cout << "最长公共子序列：" << lcs << endl;
    cout << "子序列长度：" << lcs.size() << endl;
    return 0;
}
