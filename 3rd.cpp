#include <bits/stdc++.h>
using namespace std;
const int N = 109;
const int M = 1e7;
int coins[N];
int dp[M];
const int MOD = 1000000007;

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}