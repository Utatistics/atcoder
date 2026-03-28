#include <iostream>
#include <queue>

int main() {
    int N;
    std::cin >> N;

    int A[N];
    int B[N + 1] = {0};  // count, initialize all 0
    int a;
    std::string s = "Yes";
    std::queue<int> q;

    for (int i = 0; i < N; i++) {
        std::cin >> a;
        A[i] = a;
        if (a != -1) {
            B[a] += 1;  // count how many times value a occurs
            if (B[a] > 1) {
                s = "No";
                break;
            }
        }
    }

    // Push unused numbers to the queue
    for (int i = 1; i <= N; i++) {
        if (B[i] == 0) q.push(i);
    }

    std::cout << s << std::endl;

    if (s == "Yes") {
        for (int i = 0; i < N; i++) {
            if (A[i] != -1) std::cout << A[i] << " ";
            else {
                std::cout << q.front() << " ";
                q.pop();
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

