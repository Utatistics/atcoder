#include<iostream>
#include<string>
#include<vector>

bool solve(const std::string& s) {
    int n = s.size();
    std::vector<int> sl(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') sl[i + 1] = sl[i] + 1;
        else sl[i + 1] = sl[i] - 1;
        if (sl[i + 1] < 0) return false;  // too many ')'
    }
    return sl[n] == 0;  // final balance must be zero
}

int main () {
    int N;
    std::cin >> N;

    for (int i = 0; i < (1 << N); i++) {
        std::string s = ""; // ith string 
        for (int j = N - 1; j >= 0; j--) { // higher to lower bit
            if ((i & (1 << j)) == 0) s += '(';
            else s+= ')';
        }    
        if (solve(s)) std::cout << s << std::endl;
    }

    return 0; 
}
