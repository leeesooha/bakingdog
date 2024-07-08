#include <queue>
#include <iostream>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int dist1[1002][1002];
int dist2[1002][1002];
std::string board[1002];

int main(void)
{
    std::cin >> n >> m;
    for (int x = 0; x < n; x++)
        std::cin >> board[x];

    for (int x = 0; x < n; x++) {
        std::fill(dist1[x], dist1[x] + m, -1);
        std::fill(dist2[x], dist2[x] + m, -1);
    }

    std::queue<std::pair<int, int> > Q1, Q2;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 'F') {
                dist1[x][y] = 0;
                Q1.push({x, y});
            }
            if (board[x][y] == 'J') {
                Q2.push({x, y});
                dist2[x][y] = 0;
            }
        }
    }

    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    while(!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                std::cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    std::cout << "IMPOSSIBLE";
    return 0;
}