#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class EWhitePawn {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        map<int, vector<int>> m;
        REP(i, M) {
            int x, y;
            cin >> x >> y;
            m[x].push_back(y);
        }

        set<int> s;
        s.insert(N);
        for (auto kv : m) {
            int x = kv.first;
            set<int> next, ng;
            for (auto y : m[x]) {
                auto itr = s.upper_bound(y);
                if (*itr == y + 1) {
                    next.insert(y);
                }
                itr = s.lower_bound(y);
                if (itr != s.begin()) {
                    itr--;
                    if (*itr == y - 1) {
                        next.insert(y);
                    }
                }
                if (s.count(y)) {
                    ng.insert(y);
                }
            }
            for (auto n : ng) s.erase(n);
            for (auto n : next) s.insert(n);
        }
        cout << s.size() << endl;
    }
};
