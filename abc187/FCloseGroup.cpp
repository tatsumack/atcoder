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

class FCloseGroup {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> G(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a] |= 1LL << b;
            G[b] |= 1LL << a;
        }
        vector<int> dp(1LL << N, INF);
        dp[0] = 1;
        REP(i, N) {
            REP(j, 1LL << N) {
                if (dp[j] == 1 && (G[i] & j) == j) {
                    dp[j | (1LL << i)] = 1;
                }
            }
        }

        REP(i, 1LL << N) {
            for (int j = i;; j = (j - 1) & i) {
                dp[i] = min(dp[i], dp[i ^ (i & j)] + dp[j]);
                if (j == 0) break;
            }

        }
        cout << dp.back() << endl;
    }
};
