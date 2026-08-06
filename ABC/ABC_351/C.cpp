#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::stack<int> st;
    for (int i = 0; i < N; i++) {
        st.push(A[i]);
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (a == b) 
                st.push(a + 1);
            else {
                st.push(b); st.push(a);
                break;
            }
        }
    }

    std::cout << st.size() << std::endl;
    return 0;
}

