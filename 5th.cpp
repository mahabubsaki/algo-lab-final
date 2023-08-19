#include <iostream>
#include <vector>

using namespace std;
const int N = 100009;
int dp[N];

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int sum = N; sum >= coin; sum--)
        {
            if (dp[sum - coin] == 1)
            {
                dp[sum] = 1;
            }
        }
    }

    int result = 0;
    vector<int> sums;
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] == 1)
        {
            result++;
            sums.push_back(i);
        }
    }

    cout << result << endl;
    for (int sum : sums)
    {
        cout << sum << " ";
    }

    return 0;
}
