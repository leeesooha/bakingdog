#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int map[102][102][102];
int vis[102][102][102];
int m_x, m_y, m_z;

int main(void) {
    std::cin >> m_y >> m_x >> m_z;

    for (int z = 0; z < m_z; z++) {
        for (int x = 0; x < m_x; x++) {
            for (int y = 0; y < m_y; y++) {
                vis[z][x][y] = -1;
            }
        }
    }

    std::queue<std::pair<std::pair<int, int>, int> > Q;
    for (int z = 0; z < m_z; z++) {
        for (int x = 0; x < m_x; x++) {
            for (int y = 0; y < m_y; y++) {
                std::cin >> map[z][x][y];
                if (map[z][x][y] == 1) {
                    Q.push({{z, x}, y});
                    vis[z][x][y]++;
                }
            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = cur.X.Y + dx[i];
            int ny = cur.Y + dy[i];
            int nz = cur.X.X + dz[i];
            if (nx < 0 || nx >= m_x || ny < 0 || ny >= m_y || nz < 0 || nz >= m_z) continue;
            if (vis[nz][nx][ny] >= 0 || map[nz][nx][ny] == -1) continue;
            Q.push({{nz, nx}, ny});
            vis[nz][nx][ny] = vis[cur.X.X][cur.X.Y][cur.Y] + 1;
        }
    }
    
    int ans = 0;
    for (int z = 0; z < m_z; z++) {
        for (int x = 0; x < m_x; x++) {
            for (int y = 0; y < m_y; y++) {
                if (map[z][x][y] == 0 && vis[z][x][y] == -1) {
                    std::cout << -1;
                    return 0;
                }
                ans = std::max(ans, vis[z][x][y]);
            }
        }
    }
    std::cout << ans;
    return 0;
}