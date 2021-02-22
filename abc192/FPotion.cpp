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

class FPotion {
public:
    int N, X;
    vector<int> A;

    int calc(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        dp[0][0] = 0;
        REP(i, N) {
            vector<vector<int>> next(n + 1, vector<int>(n, -1));
            next = dp;
            REP(j, n) {
                REP(k, n) {
                    if (dp[j][k] == -1) continue;
                    int val = dp[j][k] + A[i];
                    next[j + 1][val % n] = max(next[j + 1][val % n], val);
                }
            }
            dp = next;
        }
        if (dp[n][X % n] == -1) {
            return INF;
        }
        return (X - dp[n][X % n]) / n;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> X;
        A.resize(N);
        REP(i, N) cin >> A[i];
        int res = INF;
        FOR(i, 1, N) {
            res = min(res, calc(i));
        }
        cout << res << endl;
    }
};
