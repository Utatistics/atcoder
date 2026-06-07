#include <bits/stdc++.h>

using ll = long long;

struct E {
    ll ts; // time stamp
    ll t; // event type
    ll l; // length of stay
    int n; // num
    bool operator<(const E& other) const { return ts < other.ts; }
};

int main() {
    int N, K;
    std::cin >> N >> K;

    std::multiset<E> s;
    for (int i = 0; i < N; i++) {
        ll a, b;
        int c;
        std::cin >> a >> b >> c;
        s.insert({a, 0, b, c}); // arrive event
    }

    int cnt = 0;
    std::queue<E> q; // wait queue
    while ((int)s.size() > 0) {
        auto it = s.begin();
        E e = *it;
        s.erase(it);

        if (e.t == 0) { // arrive event
            if (cnt + e.n <= K && q.empty()) { // enter
                cnt += e.n;
                s.insert({e.ts + e.l, 1, e.l, e.n}); // leave event
                std::cout << e.ts << std::endl;
            }
            else q.push(e);
        }
        else { // leave event
            cnt -= e.n;
            while (!q.empty()) {
                E x = q.front();
                if (cnt + x.n <= K) { // enter
                    cnt += x.n;
                    q.pop();
                    s.insert({e.ts + x.l, 1, x.l, x.n}); // leave event
                    std::cout << e.ts << std::endl;
                }
                else break;
            }
        }
    }

    return 0;
}
