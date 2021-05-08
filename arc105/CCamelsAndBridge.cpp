#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return (int) (-1e9);
}

class CCamelsAndBridge {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> w(N), l(M), v(M);
        REP(i, N) cin >> w[i];
        set<int> s;
        REP(i, M) {
            cin >> l[i] >> v[i];
            s.insert(v[i]);
        }

        REP(i, N) {
            REP(j, M) {
                if (w[i] > v[j]) {
                    cout << -1 << endl;
                    return;
                }
            }
        }

        map<int, int> id;
        for (auto n : s) {
            id[n] = id.size();
        }

        vector<int> r(N);
        REP(i, N) r[i] = i;

        atcoder::segtree<int, op, e> seg(id.size());
        map<int, int> m;
        REP(i, M) {
            if (l[i] > m[v[i]]) {
                seg.set(id[v[i]], l[i]);
                m[v[i]] = l[i];
            }
        }

        int res = INF;
        do {
            vector<int> dist(N);
            for (int i = 0; i < N - 1; i++) {
                int cur = w[r[i]];
                for (int j = i + 1; j < N; j++) {
                    cur += w[r[j]];
                    if (cur < *s.begin()) continue;
                    auto itr = s.lower_bound(cur);
                    int right;
                    if (itr == s.end()) {
                        right = id.size();
                    } else {
                        right = id[*itr];
                    }
                    int maxL = seg.prod(0, right);
                    if (dist[j] < dist[i] + maxL) {
                        dist[j] = dist[i] + maxL;
                    }
                }
            }
            res = min(res, dist[N - 1] - dist[0]);
        } while (next_permutation(r.begin(), r.end()));
        cout << res << endl;
    }
};
