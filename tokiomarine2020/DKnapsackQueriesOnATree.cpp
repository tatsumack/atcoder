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

class DKnapsackQueriesOnATree {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> V(N), W(N);
        REP(i, N) cin >> V[i] >> W[i];
        int Q;
        cin >> Q;
        while (Q--) {
            int v, L;
            cin >> v >> L;

            vector<vector<int>> dp(20, vector<int>(L+1));
            int i = 0;
            while (v > 0) {
                int idx = v-1;
                REP(j, L+1) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                    int nj = j + W[idx];
                    if (nj > L) continue;
                    dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + V[idx]);
                }
                v /= 2;
                i++;
            }

            int res = 0;
            REP(j, L+1) res = max(res, dp[i][j]);
            cout << res << endl;
        }

    }
};
