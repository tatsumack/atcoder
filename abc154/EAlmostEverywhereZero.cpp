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


class EAlmostEverywhereZero {
public:
    int dp[101][5][2];

    void solve(std::istream& cin, std::ostream& cout) {
        string S;
        int K;
        cin >> S >> K;

        CLR(dp, 0);
        dp[0][0][0] = 1;
        REP(i, S.size()) {
            char c = S[i];
            int n = (c - '0');
            REP(j, K + 1) {
                // ぴったり
                if (n == 0) {
                    dp[i + 1][j][0] += dp[i][j][0];
                } else {
                    dp[i + 1][j][1] += dp[i][j][0];
                    dp[i + 1][j + 1][1] += dp[i][j][0] * (n - 1);
                    dp[i + 1][j + 1][0] += dp[i][j][0];
                }

                // 未満
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j + 1][1] += dp[i][j][1] * 9;
            }
        }
        cout << dp[S.size()][K][0] + dp[S.size()][K][1] << endl;
    }
};
