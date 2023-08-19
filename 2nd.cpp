#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
const int INF = 1e7;
int dist[N];
vector<vector<int>> nodes;

int dijkstra(int n, int k)
{

    dist[k] = 0;
    unordered_map<int, vector<pair<int, int>>> graph;
    for (int i = 0; i < nodes.size(); i++)
    {
        graph[nodes[i][0]].push_back({nodes[i][1], nodes[i][2]});
    }
    priority_queue<pair<int, int>> q;
    q.push({0, k});

    while (!q.empty())
    {
        int node = q.top().second;
        q.pop();
        for (auto adj_pair : graph[node])
        {
            int adj_node = adj_pair.first;
            int adj_weight = adj_pair.second;
            if (dist[node] + adj_weight >= dist[adj_node])
            {
                continue;
            }
            int new_dist = dist[node] + adj_weight;
            dist[adj_node] = new_dist;
            q.push({-1 * new_dist, adj_node});
        }
    }
    int time_taken = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            return -1;
        time_taken = max(time_taken, dist[i]);
    }
    return time_taken == INF ? -1 : time_taken;
}
int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        nodes.push_back({x, y, w});
    }
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    cout << dijkstra(n, k) << endl;

    return 0;
}