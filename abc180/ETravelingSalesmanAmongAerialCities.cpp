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

class ETravelingSalesmanAmongAerialCities {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> X(N), Y(N), Z(N);
        REP(i, N) cin >> X[i] >> Y[i] >> Z[i];
        vector<vector<int>> dp(1LL << N, vector<int>(N, INF));
        REP(k, N) {
            int ni = 1LL << k;
            int diff = abs(X[0] - X[k]) + abs(Y[0] - Y[k]) + max(0LL, Z[k] - Z[0]);
            dp[ni][k] = min(dp[ni][k], diff);
        }
        REP(i, 1LL << N) {
            REP(j, N) {
                if (dp[i][j] == INF) continue;
                if ((i >> j & 1) == 0) continue;
                REP(k, N) {
                    if ((i >> k & 1) == 1) continue;
                    int ni = i | (1LL << k);
                    int diff = abs(X[j] - X[k]) + abs(Y[j] - Y[k]) + max(0LL, Z[k] - Z[j]);
                    dp[ni][k] = min(dp[ni][k], dp[i][j] + diff);
                }
            }
        }
        cout << dp[(1LL << N) - 1][0] << endl;
    }
};
