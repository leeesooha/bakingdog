#include <iostream>
#include <queue>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int n, m, cctv_num;
int min_blind_spot = 2147483647;
int board[10][10];
int sharp[10][10];
int dx[] = {0, 1, 0, -1}; //시계방향
int dy[] = {-1, 0, 1, 0};
std::vector<std::pair<int, int> > cctvs;

//색칠 (씨씨티비 시야 비추기)
void fill_sharp(int x, int y, int dir) {

    while (x != -1 && y != -1 && x < n && y < m && board[x][y] != 6) {
        if (!(board[x][y] >= 1 && board[x][y] <= 5))
            sharp[x][y]++;
        x += dx[dir];
        y += dy[dir];
    }
}

//색칠한거 복구
void remove_sharp(int x, int y, int dir) {
    while (x != -1 && y != -1 && x < n && y < m && board[x][y] != 6) {
        if (!(board[x][y] >= 1 && board[x][y] <= 5))
            sharp[x][y]--;
        x += dx[dir];
        y += dy[dir];
    }
}

int blind_spot_check() {
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && sharp[i][j] == 0)
                res++;
        }
    }

    return (res);
}

//재귀 돌리면서 맵 모든 경우의 수 그리기
void recul(int cctv_idx) { //특정 씨씨티비 내림차순으로 확인
    //종료조건 모든 씨씨티비를 다 돌았을 때!
    if (cctv_idx < 0) {
        int blind_spot_cnt = blind_spot_check();
        if (min_blind_spot > blind_spot_cnt)
            min_blind_spot = blind_spot_cnt;
        return ;
    }

    //  if      : 1이면 1방향씩 4번 #으로 채움. 재귀 4번
    //  else if : 2이면 2방향씩 2번 #으로 채움. 재귀 2번
    //  else if : 3이면 2방향씩 4번 #으로 채움. 재귀 4번
    //  else if : 4이면 3방향씩 4번 #으로 채움. 재귀 4번
    //  else if : 5이면 4방향씩 1번 #으로 채움. 재귀 1번
        int x = cctvs[cctv_idx].first;
        int y = cctvs[cctv_idx].second;

        if (board[x][y] == 1) {
            for (int j = 0; j < 4; j++) {
                fill_sharp(x, y, j);
                recul(cctv_idx - 1);
                remove_sharp(x, y, j);
            }
        } else if (board[x][y] == 2) {
            fill_sharp(x, y, 1); //동쪽 씨씨티비 비추기 : 0은 북쪽, 1은 동쪽, 2는 남쪽, 3은 서쪽
            fill_sharp(x, y, 3);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 1);
            remove_sharp(x, y, 3);

            fill_sharp(x, y, 0);
            fill_sharp(x, y, 2);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 0);
            remove_sharp(x, y, 2);
        } else if (board[x][y] == 3) {
            fill_sharp(x, y, 0);
            fill_sharp(x, y, 1);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 0);
            remove_sharp(x, y, 1);

            fill_sharp(x, y, 1);
            fill_sharp(x, y, 2);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 1);
            remove_sharp(x, y, 2);

            fill_sharp(x, y, 2);
            fill_sharp(x, y, 3);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 2);
            remove_sharp(x, y, 3);

            fill_sharp(x, y, 3);
            fill_sharp(x, y, 0);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 3);
            remove_sharp(x, y, 0);
        } else if (board[x][y] == 4) {
            fill_sharp(x, y, 0);
            fill_sharp(x, y, 1);
            fill_sharp(x, y, 2);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 0);
            remove_sharp(x, y, 1);
            remove_sharp(x, y, 2);
            
            fill_sharp(x, y, 1);
            fill_sharp(x, y, 2);
            fill_sharp(x, y, 3);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 1);
            remove_sharp(x, y, 2);
            remove_sharp(x, y, 3);

            fill_sharp(x, y, 2);
            fill_sharp(x, y, 3);
            fill_sharp(x, y, 0);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 2);
            remove_sharp(x, y, 3);
            remove_sharp(x, y, 0);

            fill_sharp(x, y, 3);
            fill_sharp(x, y, 0);
            fill_sharp(x, y, 1);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 3);
            remove_sharp(x, y, 0);
            remove_sharp(x, y, 1);
        } else if (board[x][y] == 5) {
            fill_sharp(x, y, 0);
            fill_sharp(x, y, 1);
            fill_sharp(x, y, 2);
            fill_sharp(x, y, 3);
            recul(cctv_idx - 1);
            remove_sharp(x, y, 0);
            remove_sharp(x, y, 1);
            remove_sharp(x, y, 2);
            remove_sharp(x, y, 3);
        }
}

int main(void) {
    std::cin >> n >> m;

    //맵 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctvs.push_back({i, j});
                cctv_num++;
            }
        }
    }

    recul(cctv_num - 1);
    std::cout << min_blind_spot;
    return 0;
}