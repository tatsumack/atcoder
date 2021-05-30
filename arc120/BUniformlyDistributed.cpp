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

typedef atcoder::modint998244353 mint;

class BUniformlyDistributed {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> B(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> B[i][j];

        vector<int> cnt(H + W);
        map<char, int> m = {
                {'R', 0},
                {'B', 1},
                {'.', 2},
        };
        REP(i, H) {
            REP(j, W) {
                cnt[i + j] |= 1 << (m[B[i][j]]);
            }
        }

        mint res = 1;
        REP(i, H + W) {
            if ((cnt[i] & 3) == 3) {
                res = 0;
                continue;
            }
            if (cnt[i] == (1 << 2)) {
                res *= 2;
            }
        }
        cout << res.val() << endl;
    }
};
