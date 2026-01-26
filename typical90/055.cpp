#include <bits/stdc++.h>

int main() {
	// input processing
    int N, P, Q;
    std::cin >> N >> P >> Q;
    std::vector<int> A(N);
	for (int i = 0; i < N; ++i) std::cin >> A[i];

    // solve
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
				for (int l = 0; l < k; ++l) {
					for (int m = 0; m < l; ++m) {
						if (1LL * A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P == Q) {
							++ans;
						}
					}
				}
			}
		}
	}

    // presentation
    std::cout << ans << std::endl;
	
    return 0;
}
