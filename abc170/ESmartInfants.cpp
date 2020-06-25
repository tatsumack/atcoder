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

typedef pair<int, int> P;

class ESmartInfants {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N >> Q;

        set<P> s;
        map<int, set<P>> m;
        map<int, int> r;
        map<int, int> c;
        REP(i, N) {
            int A, B;
            cin >> A >> B;
            m[B].insert({A, i + 1});
            r[i + 1] = A;
            c[i + 1] = B;
        }
        for (auto kv : m) {
            s.insert(*kv.second.rbegin());
        }

        while (Q--) {
            int C, D;
            cin >> C >> D;

            int before = c[C];
            m[before].erase({r[C], C});
            if (s.count({r[C], C})) {
                s.erase({r[C], C});
                if (m[before].size() > 0) {
                    s.insert(*m[before].rbegin());
                }
            }

            c[C] = D;

            if (m[D].size() > 0) {
                auto kv = *m[D].rbegin();
                if (kv.first < r[C]) {
                    s.erase(kv);
                    s.insert({r[C], C});
                }
            } else {
                s.insert({r[C], C});
            }
            m[D].insert({r[C], C});
            cout << (*s.begin()).first << endl;
        }

    }
};
