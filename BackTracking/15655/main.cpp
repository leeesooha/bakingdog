#include <iostream>
#include <algorithm>

int n, m;
int input_arr[10];
int res_arr[10];

void solve(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            std::cout << res_arr[i] << " ";
        std::cout << "\n";
        return ;
    }

    int st = k;
    for (int i = st; i < n; i++) {
        if (k != 0)
            if (res_arr[k - 1] >= input_arr[i]) continue;
        res_arr[k] = input_arr[i];
        solve(k + 1);
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