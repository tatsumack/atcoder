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

class EDividingChocolate {
public:
    int H, W, K;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W >> K;
        vector<vector<int>> s(H, vector<int>(W));
        REP(i, H) REP(j, W) {
                char c;
                cin >> c;
                s[i][j] = c - '0';
            }

        int res = INF;
        REP(d, 1LL << (H - 1)) {
            int sz = __builtin_popcount(d) + 1;
            vector<int> sum(sz);
            bool ok = true;
            int tmp = sz - 1;
            REP(j, W) {
                vector<int> cur(sz);
                int id = 0;
                REP(i, H) {
                    if (s[i][j]) cur[id]++;
                    if (cur[id] > K) ok = false;
                    if (d >> i & 1) id++;
                }
                if (!ok) break;
                bool cut = false;
                REP(i, sz) {
                    if (cur[i] + sum[i] > K) {
                        cut = true;
                        tmp++;
                        break;
                    }
                }
                REP(i, sz) {
                    if (cut) {
                        sum[i] = cur[i];
                    } else {
                        sum[i] += cur[i];
                    }
                }
            }
            if (!ok) continue;
            res = min(res, tmp);
        }
        cout << res << endl;
    }
};
