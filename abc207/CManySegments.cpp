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

class CManySegments {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> v(N);
        REP(i, N) {
            int t, l, r;
            cin >> t >> l >> r;
            v[i] = {t, l, r};
        }
        int res = 0;
        REP(i, N - 1) {
            int T, L, R;
            tie(T, L, R) = v[i];
            FOR(j, i + 1, N - 1) {
                int t, l, r;
                tie(t, l, r) = v[j];
                if (r < L || R < l) continue;
                if (r == L) {
                    if (t % 2 == 0) continue;
                    if (T >= 3) continue;
                }
                if (R == l) {
                    if (T % 2 == 0) continue;
                    if (t >= 3) continue;
                }
                res++;
            }
        }
        cout << res << endl;
    }
};
