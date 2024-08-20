#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <tuple>

int ans;
int mask[25];
std::string board[5];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    for (int i = 0; i < 5; i++)
        std::cin >> board[i]; 

    std::fill(mask + 7, mask + 25, true);
    do {
        std::queue<std::pair<int, int> > Q;
        bool vis[5][5] = {};
        bool isp[5][5] = {};
        for (int i = 0; i < 25; i++) {
            if (!mask[i]) {
                int x = i / 5;
                int y = i % 5;
                isp[x][y] = true;
                if (Q.empty()) {
                    Q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        int adj = 0;
        int dasom = 0;
        while (!Q.empty()) {
            int cur_x, cur_y;
            std::tie(cur_x, cur_y) = Q.front(); Q.pop();
            adj++;
            if (board[cur_x][cur_y] == 'S')
                dasom++;
            for (int i = 0 ; i < 4; i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp[nx][ny]) continue;
                Q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        if (adj >= 7 && dasom >= 4)
            ans++;
    } while (std::next_permutation(mask, mask + 25));
    std::cout << ans;

    return 0;
}