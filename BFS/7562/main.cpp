#include <queue>
#include <iostream>

#define X first
#define Y second

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int vis[302][302];

int main(void) {
    int test_case_num;
    std::cin >> test_case_num;
    for (int i = 0; i < test_case_num; i++) {
        for (int j = 0; j < 302; j++) {
            std::fill(vis[j], vis[j] + 302, -1);
        }
        int map_size;
        std::cin >> map_size;
        int x, y;
        std::cin >> x >> y;
        vis[x][y] += 1;
        std::queue<std::pair<int, int> > Q;
        Q.push({x, y});
        std::pair<int, int> dest;
        int dest_x, dest_y;
        std::cin >> dest_x >> dest_y;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= map_size || ny < 0 || ny >= map_size) continue;
                if (vis[nx][ny] >= 0) continue;
                Q.push({nx, ny});
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            }
        }
        std::cout << vis[dest_x][dest_y] << "\n";
    }
    return 0;
}