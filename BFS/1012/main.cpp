#include <iostream>
#include <queue>

#define X first
#define Y second

int test_num, x_size, y_size, napa_num;
int farm[52][52];
int vis[52][52];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {

    std::cin >> test_num;
    for (int i = 0; i < test_num; i++) {

        std::cin >> y_size >> x_size >> napa_num;
        for (int i = 0; i < 52; i++) {
            std::fill(farm[i], farm[i] + 52, 0);
        }
        for (int i = 0; i < 52; i++) {
            std::fill(vis[i], vis[i] + 52, 0);
        }
        for (int i = 0; i < napa_num; i++) {
            int x, y;
            std::cin >> y >> x;
            farm[x][y] = 1;
        }
        std::queue<std::pair<int, int> > Q;
        int worms_num = 0;
        for (int x = 0; x < x_size; x++) {
            for (int y = 0; y < y_size; y++) {
                if (vis[x][y] == 0 && farm[x][y] == 1) {
                    worms_num++;
                    Q.push({x, y});
                    vis[x][y] = 1;
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for (int i = 0; i < 4; i++) {
                            int nx = cur.X + dx[i];
                            int ny = cur.Y + dy[i];
                            if (nx < 0 || nx >= x_size || ny < 0 || ny >= y_size || vis[nx][ny] != 0) continue;
                            if (farm[nx][ny] != 1) continue;
                            vis[nx][ny] = 1;
                            farm[nx][ny] = 0;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        std::cout << worms_num << "\n";
    }
    return 0;
}