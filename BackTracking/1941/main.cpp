#include <iostream>
#include <vector>
#include <string>

int num[25];
int arr[10];
std::string board[5];
std::vector<std::vector<int>> AllCases;

int cnt;

void findAllCases(int k, int st) {
    if (k == 7) {
        std::vector<int> a(arr, arr + 7);
        AllCases.push_back(a);
        for (int j = 0; j < 7; j++)
            std::cout << a[j];
        std::cout << std::endl;
        return ;
    }
    
    for (int i = st; i < 25; i++) {
        if (k != 0) {
            if (i <= arr[k - 1]) continue;
            int diff = i - arr[k - 1];
            if (!(diff == 1 || diff == 5))
                continue;
        }
    
        if (i + 1 < 25) {
            std::cout << "right" << std::endl;
            if (i % 5 == 0)
                continue;
            arr[k] = i;
            findAllCases(k + 1, i + 1);
        }
        if (i + 5 < 25) {
            std::cout << "down" << std::endl;
            arr[k] = i;
            findAllCases(k + 1, i + 5);
        }
    }
}

int main(void) {
    for (int i = 0; i < 25; i++)
        num[i] = i;

    for (int i = 0; i < 5; i++)
        std::cin >> board[i];

    findAllCases(0, 0);
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 7; j++) {
    //         std::cout << AllCases[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}

