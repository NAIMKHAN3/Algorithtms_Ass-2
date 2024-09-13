#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dist[101][101];

    int n, e;
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < 1e18 && dist[k][j] < 1e18) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    cin >> n >> e;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = 1e18;
            }
        }
    }

    for (int i = 0; i < e; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }

    floyd();

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (dist[x][y] == 1e18) {
            cout << -1 << endl;
        } else {
            cout << dist[x][y] << endl;
        }
    }

    return 0;
}
