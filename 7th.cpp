#include <bits/stdc++.h>
using namespace std;

const long long MaxN = 110;
const long long Inf = 1e17 + 10;

map<long long, int> visited;
long long n, m, maxPossible = 1;
long long digitCount[11];

int bfs(long long start)
{
    queue<pair<long long, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        pair<long long, int> current = q.front();
        q.pop();

        if (current.first == 0)
            return current.second;

        if (visited[current.first])
            continue;

        visited[current.first] = current.second;
        long long temp = current.first, length = 0;

        while (temp)
        {
            digitCount[temp % 10] = 1;
            temp /= 10;
            length++;
        }

        if (length >= n)
            return current.second;

        for (int i = 2; i <= 9; i++)
        {
            if (digitCount[i])
            {
                q.push({current.first * i, current.second + 1});
            }
        }

        for (int i = 0; i <= 9; i++)
        {
            digitCount[i] = 0;
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    for (long long i = 0; i < n; i++)
    {
        maxPossible *= 10;
    }

    cout << bfs(m) << endl;
    return 0;
}