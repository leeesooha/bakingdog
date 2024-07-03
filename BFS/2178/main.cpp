#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

std::string board[102];
int dist[102][102];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void)
{
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) //board 받기
        std::cin >> board[i];

    for (int i = 0; i < n; i++) {
        std::fill(dist[i], dist[i] + m, -1); // fill (채울시작위치, 채울마지막위치(마지막위치 포함안함), 채울값)
    }

    std::queue<std::pair<int, int> > Q;
    Q.push({0, 0});
    dist[0][0] = 0;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    std::cout << dist[n - 1][m - 1] + 1;
    return (0);
}