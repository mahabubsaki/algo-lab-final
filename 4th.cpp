#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i].first;
        values[i].second = i + 1;
    }

    sort(values.begin(), values.end());

    int left = 0, right = n - 1;

    while (left < right)
    {
        int currentSum = values[left].first + values[right].first;

        if (currentSum == x)
        {
            cout << values[left].second << " " << values[right].second << endl;
            return 0;
        }
        else if (currentSum < x)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
