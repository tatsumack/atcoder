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

class EPatisserieABC2 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> dp(4, vector<int>(4 * N + 10));
        dp[0][0] = 1;
        REP(i, 3) {
            REP(j, 3 * N) {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + N + 1] -= dp[i][j];
            }
            REP(j, 3 * N) {
                dp[i + 1][j + 1] += dp[i + 1][j];
            }
        }

        int x = -1;
        REP(j, 3 * N + 1) {
            if (K - dp[3][j] <= 0) {
                x = j;
                break;
            }
            K -= dp[3][j];
        }
        int y = -1;
        FOR(j, 1, N) {
            int r = x - j;
            if (r > 2 * N) continue;
            if (K - dp[2][r] <= 0) {
                y = j;
                break;
            }
            K -= dp[2][r];
        }
        int z = -1;
        FOR(j, 1, N) {
            int r = x - y - j;
            if (r > N) continue;
            if (K - dp[1][r] <= 0) {
                z = j;
                break;
            }
            K -= dp[1][r];
        }

        cout << y << " " << z << " " << x - (y + z) << endl;
    }
};
