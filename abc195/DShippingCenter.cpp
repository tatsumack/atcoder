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

class DShippingCenter {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> W(N), V(N), X(M);
        REP(i, N) cin >> W[i] >> V[i];
        REP(i, M) cin >> X[i];
        vector<pair<int, int>> v(N);
        REP(i, N) {
            v[i] = {V[i], W[i]};
        }
        sort(v.rbegin(), v.rend());
        while (Q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            vector<int> tmp;
            REP(i, M) {
                if (l <= i && i <= r) continue;
                tmp.push_back(X[i]);
            }
            sort(tmp.begin(), tmp.end());
            vector<int> used(N);
            int res = 0;
            REP(i, tmp.size()) {
                REP(j, v.size()) {
                    if (used[j]) continue;
                    if (v[j].second <= tmp[i]) {
                        res += v[j].first;
                        used[j] = true;
                        break;
                    }
                }
            }
            cout << res << endl;
        }
    }
};
