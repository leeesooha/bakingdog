#include <iostream>

std::string map[66];

bool isSameColor(int row, int col, int n) {
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (map[row][col] != map[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve(int row, int col, int n) {
    if (isSameColor(row, col, n) == true) {
        std::cout << map[row][col];
        return ;
    }
    std::cout << "(";
    int n2 = n / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            solve(row + i * n2, col + j * n2, n2);
    }
    std::cout << ")";
}

int main(void) {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> map[i];
    }
    solve(0, 0, N);
    return 0;
}