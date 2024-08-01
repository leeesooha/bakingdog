#include <iostream>

int arr[2189][2189];
int cnt[3];

bool isSameColor(int row, int col, int n) {
    for (int i = row; i < (row + n); i++) {
        for (int j = col; j < (col + n); j++) {
            if (arr[row][col] != arr[i][j])
                return false;
        }
    }
    return true;
}

void recur(int row, int col, int n) {
    if (isSameColor(row, col, n) == true) {
        cnt[arr[row][col] + 1]++;
        return ;
    }

    int n2 = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recur(row + i * n2, col + j * n2, n2);
        }
    }
}

int main(void) {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
        }
    }

    recur(0, 0, N);
    
    for (int i = 0; i < 3; i++)
        std::cout << cnt[i] << "\n";
    return 0;
}