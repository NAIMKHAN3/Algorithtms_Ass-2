#include <bits/stdc++.h>
#define ll long long int
using namespace std;




class Edge {
    public:
    ll u, v, w;
    Edge(ll x, ll y, ll z){
        u = x;
        v = y;
        w = z;
    }
};

vector<Edge> edges;
long long int dist[1001];
bool hasNegativeCycle = false;

void bellmanFord(int s, int n) {
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] != 1e18 && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for (Edge e : edges) {
        if (dist[e.u] != 1e18 && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while (e--) {
        ll x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }

    int s;
    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
    }

    bellmanFord(s, n);

    int t;
    cin >> t;

    if (hasNegativeCycle) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        while (t--) {
            int d;
            cin >> d;
            if (dist[d] == 1e18) {
                cout << "Not Possible" << endl;
            } else {
                cout << dist[d] << endl;
            }
        }
    }

    return 0;
}
