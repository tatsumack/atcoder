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

class ESequenceMatching {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        REP(i, N) cin >> A[i];
        REP(i, M) cin >> B[i];
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
        REP(i, N + 1) dp[i][0] = i;
        REP(j, M + 1) dp[0][j] = j;
        FOR(i, 1, N) {
            FOR(j, 1, M) {
                dp[i][j] = min({
                                       dp[i - 1][j] + 1,
                                       dp[i][j - 1] + 1,
                                       dp[i - 1][j - 1] + ((A[i - 1] == B[j - 1]) ? 0 : 1)
                               });
            }
        }
        cout << dp[N][M] << endl;
    }
};
