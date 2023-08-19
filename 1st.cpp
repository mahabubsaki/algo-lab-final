#include <iostream>
#include <vector>

using namespace std;

const int N = 1009;

int grid[N][N];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y)
{
    int result = grid[x][y];
    grid[x][y] = 0;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny) && grid[nx][ny] > 0)
        {
            result = result + dfs(nx, ny);
        }
    }

    return result;
}

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> grid[i][j];
            }
        }

        int maxVolume = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] > 0)
                {
                    maxVolume = max(maxVolume, dfs(i, j));
                }
            }
        }

        cout << maxVolume << endl;
    }

    return 0;
}