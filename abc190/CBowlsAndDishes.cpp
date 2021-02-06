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

class CBowlsAndDishes {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int>> v(M);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            v[i] = {a, b};
        }
        int K;
        cin >> K;
        vector<pair<int, int>> k(K);
        REP(i, K) {
            int c, d;
            cin >> c >> d;
            c--, d--;
            k[i] = {c, d};
        }
        int res = 0;
        REP(i, 1LL << K) {
            vector<int> d(N);
            REP(j, K) {
                if (i >> j & 1) {
                    d[k[j].first]++;
                } else {
                    d[k[j].second]++;
                }
            }
            int tmp = 0;
            REP(j, M) {
                if (d[v[j].first] == 0) continue;
                if (d[v[j].second] == 0) continue;
                tmp++;
            }
            res = max(res, tmp);
        }
        cout << res << endl;
    }
};
