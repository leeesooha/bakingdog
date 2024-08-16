#include <iostream>
#include <algorithm>

int isused[10];
int result_arr[10];
int input_arr[10];
int n, m;

void solve(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            std::cout << result_arr[i] << " ";
        std::cout << "\n";
        return ;
    }

    for (int i = 0; i < n; i++) {
        if (isused[i] == true) continue;
        isused[i] = true;
        result_arr[k] = input_arr[i];
        solve(k + 1);
        isused[i] = false;
    }
}

int main(void) {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> input_arr[i];

    std::sort(input_arr, input_arr + n);

    solve(0);

    return 0;
}