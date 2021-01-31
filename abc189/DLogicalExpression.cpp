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

class DLogicalExpression {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<string> S(N);
        REP(i, N) cin >> S[i];
        vector<vector<int>> dp(N + 1, vector<int>(2));
        dp[0][0] = dp[0][1] = 1;
        REP(i, N) {
            if (S[i] == "AND") {
                // TRUE
                dp[i + 1][1] += dp[i][1];
                dp[i + 1][0] += dp[i][0];
                // FALSE
                dp[i + 1][0] += dp[i][1];
                dp[i + 1][0] += dp[i][0];
            } else {
                // TRUE
                dp[i + 1][1] += dp[i][1];
                dp[i + 1][1] += dp[i][0];
                // FALSE
                dp[i + 1][1] += dp[i][1];
                dp[i + 1][0] += dp[i][0];
            }
        }
        cout << dp[N][1] << endl;
    }
};
