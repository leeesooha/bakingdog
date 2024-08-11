#include <iostream>
#include <queue>

#define X first

int arr[100002];
int vis[100002];
int dx[] = {1, -1};

int main(void) {
    int N, M;
    std::cin >> N >> M;

    std::fill(vis, vis + 100002, INT32_MAX);

    vis[N] = 0;
    arr[M] = 1;
    std::queue<int> Q;
    Q.push(N);
    if (N == M) {
        std::cout << 0;
        return 0;
    }
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop(); 
        for (int i = 2; i >= 0; i--) {
            int nx;
            if (i == 2) {
                nx = cur * 2;
                if (nx < 0 || nx > 100000 || vis[nx] != INT32_MAX) continue;
                if (arr[nx] == 1) {
                    std::cout << vis[cur];
                    return 0;
                }
                if (vis[nx] > vis[cur])
                    vis[nx] = vis[cur];
            } else {
                nx = cur + dx[i];
                if (nx < 0 || nx > 100000 || vis[nx] != INT32_MAX) continue;
                if (arr[nx] == 1) {
                    std::cout << vis[cur] + 1;
                    return 0;
                }
                if (vis[nx] > vis[cur])
                    vis[nx] = vis[cur] + 1;
            }
            Q.push(nx);
        }
    }
    return 0;
}