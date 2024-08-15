#include <iostream>

// bool isused[10];
int arr[10];
int N, M;

void solve(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        return ;
    }
    for (int i = 1; i <= N; i++) {
        // isused[i] = true; //바킹독의 백트래킹의 전형적형태이지만 현 문제에선 필요없음.
        arr[k] = i;
        solve(k + 1);
        // isused[i] = false;
    }
}

int main(void) {
    std::cin >> N >> M;

    solve(0);
    return 0;
}