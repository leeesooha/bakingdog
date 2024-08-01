#include <iostream>

int N, White, Blue;
int arr[1026][1026];

bool check(int row, int col, int n)
{
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (arr[row][col] != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void recur(int row, int col, int n)
{
    if (check(row, col, n) == true) {
        if (arr[row][col] == 1)
            Blue++;
        else
            White++;
        return ;
    }
    recur(row, col, n / 2);
    recur(row + (n / 2), col, n / 2);
    recur(row + (n / 2), col + (n / 2), n / 2);
    recur(row, col + (n / 2) , n / 2);
}

int main(void)
{
    std::cin >> N;    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
        }
    }

    recur(0, 0, N);
    std::cout << White << "\n" << Blue;
}