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

class DPond {
public:
    int N, K;
    vector<vector<int>> A;

    bool check(int x) {
        vector<vector<int>> dp(N, vector<int>(N));
        REP(i, N) {
            REP(j, N) {
                dp[i][j] = A[i][j] >= x ? 1 : 0;
                if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        FOR(i, K - 1, N - 1) {
            FOR(j, K - 1, N - 1) {
                int num = dp[i][j];
                if (i - K >= 0) num -= dp[i - K][j];
                if (j - K >= 0) num -= dp[i][j - K];
                if (i - K >= 0 && j - K >= 0) num += dp[i - K][j - K];
                if (num < K * K / 2 + 1) {
                    return false;
                }
            }
        }
        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> K;
        A = vector<vector<int>>(N, vector<int>(N));
        REP(i, N) REP(j, N) cin >> A[i][j];

        int l = 0;
        int r = INF;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
};