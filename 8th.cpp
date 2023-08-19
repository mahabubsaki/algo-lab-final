#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
int dp[N][N];
int n, m;
string s, t;

int LCS(int i, int j)
{
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        int ans = 1 + LCS(i + 1, j + 1);
        dp[i][j] = ans;
        return ans;
    }

    int ans = max(LCS(i + 1, j), LCS(i, j + 1));
    dp[i][j] = ans;
    return ans;
}

string findLCS()
{
    LCS(0, 0);
    string result;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            result += s[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

int main()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << findLCS() << endl;

    return 0;
}
