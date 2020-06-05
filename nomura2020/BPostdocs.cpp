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

class BPostdocs {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string T;
        cin >> T;

        vector<vector<int>> dp(T.size() + 1, vector<int>(2));
        vector<vector<int>> par(T.size(), vector<int>(2,-1));
        for (int i = 0; i < T.size(); i++) {
            auto c = T[i];
            if (c == 'D') {
                dp[i + 1][0] = max(dp[i][0] + 1, dp[i][1] + 2);
                if (dp[i][0]+1 > dp[i][1]+2) {
                    par[i][0] = 0;
                } else {
                    par[i][0] = 1;
                }
            }
            if (c == 'P') {
                dp[i + 1][1] = max(dp[i][0], dp[i][1]);
                if (dp[i][0] > dp[i][1]) {
                    par[i][1] = 0;
                } else {
                    par[i][1] = 1;
                }
            }
            if (c == '?') {
                // D
                dp[i + 1][0] = max(dp[i][0] + 1, dp[i][1] + 2);
                if (dp[i][0] + 1 > dp[i][1] + 2) {
                    par[i][0] = 0;
                } else {
                    par[i][0] = 1;
                }
                // P
                dp[i + 1][1] = max(dp[i][0], dp[i][1]);
                if (dp[i][0] > dp[i][1]) {
                    par[i][1] = 0;
                } else {
                    par[i][1] = 1;
                }
            }
        }
        int cur = dp[T.size()][0] > dp[T.size()][1] ? 0 : 1;
        string res = cur == 0 ? "D" : "P";
        for (int i = T.size() - 1; i >= 1; i--) {
            res += par[i][cur] == 0 ? "D" : "P";
            cur = par[i][cur];
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
};
