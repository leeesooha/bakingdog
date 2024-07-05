#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int board[1002][1002];
int dist[1002][1002];

int main(void)
{
    int n, m;
    std::cin >> m >> n;
    std::queue<std::pair<int, int> > Q;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            std::cin >> board[x][y];
            if (board[x][y] == 1)
                Q.push({x, y});
            if (board[x][y] == 0)
                dist[x][y] = -1;
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (dist[x][y] == -1) {
                std::cout << -1;
                return 0;
            }
            ans = std::max(ans, dist[x][y]);
        }
    }
    std::cout << ans;
    return 0;
}