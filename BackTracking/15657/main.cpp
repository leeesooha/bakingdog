#include <iostream>
#include <algorithm>

int n, m;
int arr[10];
int res[10];

void solve(int k, int st) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            std::cout << res[i] << " ";
        std::cout << "\n";
        return ;
    }

    for (int i = st; i < n; i++) {
        res[k] = arr[i];
        solve(k + 1, i);
    }
}

int main(void) {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::sort(arr, arr + n);

    solve(0, 0);

    return 0;
}