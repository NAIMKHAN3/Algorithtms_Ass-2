#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1001];
long long int dist[1001];

void dijkstra(int s, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int src = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        if (dis > dist[src])
        {
            continue;
        }

        for (pair<int, int> edge : graph[src])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[src] + w < dist[v])
            {
                dist[v] = dist[src] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    int s;
    cin >> s;

    dijkstra(s, n);

    int t;
    cin >> t;
    while (t--)
    {
        int d, dw;
        cin >> d >> dw;

        if (dist[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
