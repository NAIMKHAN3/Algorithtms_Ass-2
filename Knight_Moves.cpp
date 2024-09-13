#include <bits/stdc++.h>
using namespace std;

int dist[101][101];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int minStep(int n, int m, int ki, int kj, int qi, int qj)
{
    if (ki == qi && kj == qj)
    {
        return 0;
    }

    queue<pair<int, int>> q;

    q.push({ki, kj});
    dist[ki][kj] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int x = parent.first;
        int y = parent.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;

                if (nx == qi && ny == qj)
                {
                    return dist[nx][ny];
                }

                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int ki, kj;
        cin >> ki >> kj;

        int qi, qj;
        cin >> qi >> qj;

        memset(dist, -1, sizeof(dist));

        cout << minStep(n, m, ki, kj, qi, qj) << endl;
    }

    return 0;
}
