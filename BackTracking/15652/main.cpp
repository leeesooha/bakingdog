#include <iostream>

int arr[10];
int N, M;

void solve(int k) {

    if (k == M) {
        for (int i = 0; i < M; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        return ;
    }

    int st = 1;
    if (k != 0) st = arr[k - 1];
    for (int i = st; i <= N; i++) {
        arr[k] = i;
        solve(k + 1);
    }
}

int main(void) {
    std::cin >> N >> M;

    solve(0);

    return 0;
}