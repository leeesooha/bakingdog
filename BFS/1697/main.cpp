#include <iostream>
#include <queue>

int dist[100002];
int n, k;

int main(void) {
    std::cin >> n >> k;
    std::fill(dist, dist + 100001, -1);
    dist[n] = 0;
    std::queue<int> Q;
    Q.push(n);
    while (dist[k] == -1) {
        int cur = Q.front(); Q.pop();
        for (int pos : {cur - 1, cur + 1, 2 * cur}) {
            if (pos < 0 || pos > 100000) continue;
            if (dist[pos] != -1) continue;
            dist[pos] = dist[cur] + 1;
            Q.push(pos);
        }
    }
    std::cout << dist[k];
    return 0;
}