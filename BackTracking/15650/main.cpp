#include <iostream>

// bool isused[10];
int arr[10];
int N, M;

void solution(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        return ;
    }
    int st = 1;
    if(k != 0)
        st = arr[k - 1] + 1;
    for (int i = st; i <= N; i++) {
        // if (isused[i] == true) // 정답코드에는 있었음. 그러나 어차피 st를 바로 위줄에서 이전값보다 크게 설정하고 for문을 진입하므로 필요없음. 
        //     continue;
        // isused[i] = true;
        arr[k] = i;
        solution(k + 1);
        // isused[i] = false;
    }
}

int main(void) {
    std::cin >> N >> M;

    solution(0);

    return 0;
}