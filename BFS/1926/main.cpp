#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

int map[502][502];
int vis[502][502];
int mx = 0;
int n = 0;
int m = 0;
int draw_total_cnt = 0;
int dir_x[] = {1, 0, -1, 0};
int dir_y[] = {0, 1, 0, -1};

int main(void)
{
    std::cin >> n >> m;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
            std::cin >> map[x][y];
    
    for (int s_x = 0; s_x < n; s_x++) {
        for (int s_y = 0; s_y < m; s_y++) {
            if (map[s_x][s_y] == 0 || vis[s_x][s_y] == 1) continue;
            vis[s_x][s_y] = 1;
            std::queue<std::pair<int, int> > Q;
            std::pair<int, int> s_pair;
            s_pair.X = s_x;
            s_pair.Y = s_y;
            Q.push(s_pair);
            draw_total_cnt++;
            int area = 0;
            while(!Q.empty()) {
                area++;
                std::pair<int, int> cur;
                cur = Q.front(); Q.pop();
                for (int i = 0; i < 4; i++) {
                    int side_x = cur.X + dir_x[i];
                    int side_y = cur.Y + dir_y[i];
                    if (side_x < 0 || side_x >= n || side_y < 0 || side_y >= m) continue;
                    if (map[side_x][side_y] == 0 || vis[side_x][side_y] == 1) continue;
                    vis[side_x][side_y] = 1;
                    Q.push({side_x, side_y});
                }
            }
            mx = std::max(mx, area);
        }
    }
    std::cout << draw_total_cnt << '\n' << mx;
    return 0;
}