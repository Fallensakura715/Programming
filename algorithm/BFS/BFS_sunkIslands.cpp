#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int n;
char grid[N][N];
bool vis[N][N];
int cnt = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool isSunk(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && grid[nx][ny] == '.') {
            return true;
        }
    }
    return false;
}

bool bfs(int x0, int y0)  {
    queue<PII> q,islands;
    q.emplace(x0, y0);
    vis[x0][y0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                if (grid[nx][ny] == '#') {
                    q.emplace(nx, ny);
                    if (!isSunk(nx, ny)) {
                        islands.emplace(nx, ny);
                    }
                }
            }
        }
    }
    return islands.empty();
}

int main() {
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#' && !vis[i][j] && bfs(i, j)) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
