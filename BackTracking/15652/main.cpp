#include <iostream>

int arr[10];
// int isused[10];
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
        // if (isused[i] == true) continue; //isused 쓸필요 없음. 문제조건: 중복수열을 방지, 수열안에서 숫자중복은 허용, 비내림차순 -> 비내림차순일때 for문은 오름차순방향으로 흐르며, st를 매번 이전 k값으로 수정하기 때문에 중복수열이 나올 수 없게됨. 그래서 isused로 체크안해도됨. 
        // isused[i] = true;
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