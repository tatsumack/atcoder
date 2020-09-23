#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

int dp[3005][3005][5];
int val[3005][3005];

class EPickingGoods {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        CLR(dp, -1);
        int R, C, K;
        cin >> R >> C >> K;
        REP(i, K) {
            int r, c, v;
            cin >> r >> c >> v;
            r--, c--;
            val[r][c] = v;
        }

        dp[0][0][0] = 0;
        REP(i, R) {
            REP(j, C) {
                REP(k, 4) {
                    if (dp[i][j][k] == -1) continue;
                    // 拾わない
                    if (i + 1 < R) dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
                    if (j + 1 < C) dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);

                    // 拾う
                    if (k < 3) {
                        if (i + 1 < R) dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k] + val[i][j]);
                        if (j + 1 < C) dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + val[i][j]);
                    }
                }
            }
        }

        int res = 0;
        REP(i, 4) {
            int tmp = dp[R - 1][C - 1][i];
            if (i < 3) tmp += val[R-1][C-1];
            res = max(res, tmp);
        }
        cout << res << endl;
    }
};