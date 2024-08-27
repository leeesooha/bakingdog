#include <iostream>
#include <algorithm>

int n, m;
int res[10];
int arr[10];

void solve(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            std::cout << res[i] << " ";
        std::cout << "\n";
        return ;
    }

    for (int i = 0; i < n; i++) {
        res[k] = arr[i];
        solve(k + 1);
    }
}

int main(void) {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    
    std::sort(arr, arr + n);

    solve(0);
    
    return 0;
}