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

int dp[1000005][2];

void chmin(int& v, int x) {
    v = min(v, x);
}

class EPayment {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;

        REP(i, s.size() + 1) REP(j, 2) dp[i][j] = INF;
        dp[0][0] = 0;

        REP(i, s.size()) {
            int n = s[i] - '0';
            chmin(dp[i + 1][0], dp[i][0] + n);
            chmin(dp[i + 1][1], dp[i][0] + 1 + 10 - n);
            chmin(dp[i + 1][1], dp[i][1] + 9 - n);
            chmin(dp[i + 1][0], dp[i][1] + n);
        }
        cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;
    }
};
