#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// void debug(int t, int i, int j, int s, const std::unordered_map<int, int> &m) {
//     std::cout << t << ": i=" << i << ", j=" << j << ", s=" << s;
//     std::cout << " { ";
//     for (const auto &p : m) {
//         if (p.first > 0 && p.second > 0)
//             std::cout << p.first << ":" << p.second << " ";
//     }
//     std::cout << "}\n";
// }

int main() {
	// input processing
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];

    // solve
	int j = 0;
    int ans = 0; int s = 0;
    std::unordered_map<int, int> m;
	for (int i = 0; i <= N; i++) {
		while (j < N && s <= K && !(s == K && m[a[j]] == 0)) {
            // debug(0, i, j, s, m);
            s += (m[a[j]] == 0) ? 1 : 0;
            m[a[j]] += 1;
            ++j;
            // debug(1, i, j, s, m);
		}
        
		ans = std::max(ans, j - i);
        // std::cout << "->j=" << j << ", i=" << i << ", ans=" << j - i << std::endl; 
        if (j == i) ++j;
        if (j != i && m[a[i]] == 1) s--;        
		m[a[i]] -= 1;
        // debug(2, i, j, s, m);
        // std::cout << std::endl;
	}

	std::cout << ans << std::endl;
	return 0;
}
