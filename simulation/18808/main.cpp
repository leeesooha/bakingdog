#include <iostream>

int n, m, k, r, c, res;
int sticker[12][12];
int board[42][42];

// 모눈 종이 회전
void rotate_sticker() {
    int temp[12][12];
    int temp_int;

    //스티커 복사
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            temp[i][j] = sticker[i][j];
        }
    }

    //원본스티커 초기화
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::fill(sticker[i], sticker[i] + 12, -1);
        }
    }

    //스티커 회전 적용
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sticker[i][j] = temp[j][r - 1 - j];
        }
    }
    temp_int = r;
    r = c;
    c = temp_int;
}

//모눈 종이 그리기 함수
void stick_sticker(int x, int y) {
    //x, y 에 모눈종이 그리기
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1)
                board[x + i][y + j] = 1;
        }
    }
}

// 노트북에 모눈 종이 어디 들어가는지 확인 함수
std::pair<int, int> where_stick() {
    bool isValid = true;
    std::pair<int, int> pos;

    // 모든 노트북 좌표 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            isValid = true;
            int sr, sc;
            for (sr = 0; sr < r && isValid; sr++) {
                for (sc = 0; sc < c && isValid; sc++) {
                    if (i + sr >= n || j + sc >= m) {
                        isValid = false;
                        break;
                    }
                    if (sticker[sr][sc] == 1 && board[i + sr][j + sc] != 0) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid == false)
                    break ;
            }
            if (!(sr == r && sc == c))
                isValid = false;
            if (isValid == false)
                continue;
            pos = {i, j};
            return (pos);
        }
    }
    pos = {-1, -1};
    return (pos);
}

int main(void) {

    std::cin >> n >> m >> k;    //노트북 크기, 모눈종이 개수 입력 받기

    for (int i = 0; i < k; i++) { //각 모눈종이 모두 확인반복
        std::cin >> r >> c;
        for (int j = 0; j < 10; j++)
            std::fill(sticker[j], sticker[j] + 10, -1);
        for (int j = 0; j < r; j++) {   //모눈 종이 하나 입력 받기
            for (int l = 0; l < c; l++) {
                std::cin >> sticker[j][l];
            }
        }

        // std::cout << "----0" << "\n";  
        // 노트북에 모눈 종이 4방향 다 넣어보기
        for (int j = 0; j < 4; j++) {
            //노트북에 모눈 종이 어디에 들어가는지 확인 == true or false
            std::pair<int, int> pos = where_stick();
            // std::cout << "----1" << "\n";
            std::cout << "[" << pos.first << "," << pos.second << "]" << "\n";
            if (!(pos.first == -1)) { //if 양수
                stick_sticker(pos.first, pos.second);   // 그 자리에 삽입
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        std::cout << board[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                std::cout << "\n";
                break ;
            }
            //모눈 종이 회전
            rotate_sticker();
            std::cout << "\n\nrotate: \n";
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    std::cout << sticker[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }

    }
    // std::cout << "----10" << "\n";
    //노트북에 1 적힌거 개수 셈.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1)
                res++;
        }
    }
    std::cout << res;
    return (0);
}