#include <iostream>
#include <queue>

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int fire[1002][1002];
int human[1002][1002];
int flag;

int main(void) {
    int test_case_num;
    std::cin >> test_case_num;
    for (int i = 0; i < test_case_num; i++) {

        for (int init_x = 0; init_x < 1002; init_x++) {
            std::fill(fire[init_x], fire[init_x] + 1002, -1);
        }
        for (int init_x = 0; init_x < 1002; init_x++) {
            std::fill(human[init_x], human[init_x] + 1002, -1);
        }
        std::queue<std::pair<int, int> > fire_Q;
        std::queue<std::pair<int, int> > human_Q;

        int m_x, m_y;
        std::cin >> m_y >> m_x;
        for (int x = 0; x < m_x; x++) {
            std::string arg;
            std::cin >> arg;
            for (int y = 0; y < m_y; y++) {
                if (arg[y] == '#') {
                    fire[x][y] = -2;
                    human[x][y] = 0;
                } else if (arg[y] == '*') {
                    fire_Q.push({x, y});
                    fire[x][y] = 0;
                } else if (arg[y] == '@') {
                    human_Q.push({x, y});
                    human[x][y] = 0;
                }
            }
        }

        while(!fire_Q.empty()) {
            auto cur = fire_Q.front(); fire_Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= m_x || ny < 0 || ny >= m_y) continue;
                if (fire[nx][ny] >= 0 || fire[nx][ny] == -2) continue;
                fire_Q.push({nx, ny});
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            }
        }
        flag = 0;
        while (!human_Q.empty()) {
            auto cur = human_Q.front(); human_Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= m_x || ny < 0 || ny >= m_y) {
                    std::cout << human[cur.X][cur.Y] + 1 << "\n";
                    flag = 1;
                    break ;
                }
                if ((fire[nx][ny] <= (human[cur.X][cur.Y] + 1) && fire[nx][ny] != -1) || human[nx][ny] >= 0) continue;
                human_Q.push({nx, ny});
                human[nx][ny] = human[cur.X][cur.Y] + 1;
            }
            if (flag == 1)
                break ;
        }
        if (flag != 1)
            std::cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}