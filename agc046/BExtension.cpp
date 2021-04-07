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

mint dp[3005][3005][3][3];

class BExtension {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        CLR(dp, 0);
        dp[A][B][0][0] = 1;
        FOR(i, A, C) {
            FOR(j, B, D) {
                REP(a, 3) {
                    REP(b, 3) {
                        dp[i + 1][j][1][b] += dp[i][j][a][b] * (j - 1);
                        dp[i + 1][j][1][min(2LL, b + 1)] += dp[i][j][a][b];

                        if (i == A || a != 1) dp[i][j + 1][a][1] += dp[i][j][a][b] * (i - 1);
                        dp[i][j + 1][min(2LL, a + 1)][1] += dp[i][j][a][b];
                    }
                }
            }
        }

        mint res = 0;
        REP(a, 3) {
            REP(b, 3) {
                res += dp[C][D][a][b];
            }
        }
        cout << res.val() << endl;
    };
};