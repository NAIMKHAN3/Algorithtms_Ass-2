#include <bits/stdc++.h>
using namespace std;

int n, m;
char graph[1001][1001];
bool visited[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !visited[x][y]);
}

bool bfs(int sX, int sY, int dX, int dY) {
    queue<pair<int, int>> q;
    q.push({sX, sY});
    visited[sX][sY] = true;

    while (!q.empty()) {
        pair<int,int> parent = q.front();
        int x= parent.first;
        int y= parent.second;
        q.pop();

        if (x == dX && y == dY) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nX = x + dx[i];
            int nY = y + dy[i];

            if (isValid(nX, nY)) {
                visited[nX][nY] = true;
                q.push({nX, nY});
            }
        }
    }

    return false;
}

int main() {

    cin >> n >> m;
   memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int sX, sY, dX, dY;
    cin >> sX >> sY;
    cin >> dX >> dY;

    if (bfs(sX, sY, dX, dY)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
