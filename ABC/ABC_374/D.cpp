#include <bits/stdc++.h>

static const double MAX = 1e18;

using P = std::pair<int, int>;

int main() {
    int N, S, T;
    std::cin >> N >> S >> T;

    std::vector<std::pair<P, P>> r;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        P p = {a, b};
        P q = {c, d};
        r.push_back({p, q});
    }

    auto f = [&](P p, P q) -> double { // dist
        double a = (p.first - q.first) * (p.first - q.first);
        double b = (p.second - q.second) * (p.second - q.second);
        return std::sqrt(a + b);
    };

    double ans = MAX;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = i;
    
    do {
    double cost = MAX;
        {
            P p0 = {0, 0};
            auto [p, q] = r[A[0]];
            double ci = std::min(f(p0, p) / S, f(p0, q) / S);
            cost = ci + f(p, q) / T;
        }

        for (int i = 1; i < N; i++) {
            auto [p, q] = r[A[i]];
            auto [pp, pq] = r[A[i - 1]]; // previous

            double c = MAX;

            c = std::min(c, f(pp, p) / S + f(p, q));
            c = std::min(c, f(pp, q) / S);
            c = std::min(c, f(pq, p) / S);
            c = std::min(c, f(pq, q) / S);

            cost += c + f(p, q) / T;
        }
        ans = std::min(ans, cost);
    } while (std::next_permutation(A.begin(), A.end()));
    
    std::cout << std::fixed << std::setprecision(17) << ans << std::endl; // double
    return 0;
}


