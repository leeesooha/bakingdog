#include <iostream>
#include <queue>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
std::string board[102];
int vis[102][102];
int n, color_weakness, not_color_weakness;

int main(void) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> board[i];
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (vis[x][y] == 0) {
                color_weakness++;
                int color = board[x][y];
                std::queue<std::pair<int, int> > Q;
                Q.push({x, y});
                vis[x][y] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] != color || vis[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 102; i++) {
        std::fill(vis[i], vis[i] + 102, 0);
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (vis[x][y] == 0) {
                not_color_weakness++;
                int color = board[x][y];
                std::queue<std::pair<int, int> > Q;
                Q.push({x, y});
                vis[x][y] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (color == 'R' || color == 'G') {
                            if (!(board[nx][ny] == 'R' || board[nx][ny] == 'G') || vis[nx][ny] == 1) continue;
                        }
                        else {
                            if (board[nx][ny] != color || vis[nx][ny] == 1) continue;
                        }
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }

    std::cout << color_weakness << " " << not_color_weakness;
    return 0;
}