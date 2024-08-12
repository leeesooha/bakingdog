#include <iostream>
#include <queue>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
std::string arr[102];
int vis[102][102];

int main(void) {
    int N, M;
    std::cin >> M >> N;

    for (int i = 0; i < 102; i++) {
        std::fill(vis[i], vis[i] + 102, INT32_MAX);
    }
    
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::queue<std::pair<int, int> > Q;
    Q.push({0, 0});
    vis[0][0] = 0;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (arr[nx][ny] ==  '1') {
                if (vis[nx][ny] > vis[cur.X][cur.Y] + 1) {
                    vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                }
            } else {
                if (vis[nx][ny] > vis[cur.X][cur.Y]) {
                    vis[nx][ny] = vis[cur.X][cur.Y];
                    Q.push({nx, ny});
                }
            }
        }
    }
    std::cout << vis[N - 1][M - 1];
    return 0;
}