#include <iostream>
#include <vector>
#include <queue>

int egg_num, broken_egg_num, max;
int s[10];
int w[10];

void solve(int k) {
    if (k == egg_num) {
        if (broken_egg_num > max)
            max = broken_egg_num;
        return ;
    }

    if (s[k] <= 0 || broken_egg_num == egg_num - 1) {
        solve(k + 1);
        return ;
    }
    for (int i = 0; i < egg_num; i++) {
        if (k == i || s[i] <= 0) continue;
        s[k] -= w[i];
        s[i] -= w[k];
        if (s[k] <= 0)
            broken_egg_num++;
        if (s[i] <= 0)
            broken_egg_num++;
        solve(k + 1);
        if (s[k] <= 0)
            broken_egg_num--;
        if (s[i] <= 0)
            broken_egg_num--;
        s[k] += w[i];
        s[i] += w[k];
    }
}

int main(void) {
    std::cin >> egg_num;
    for (int i = 0; i < egg_num; i++) {
        std::cin >> s[i] >> w[i];
    }
    
    solve(0);
    std::cout << max;

    return 0;
}