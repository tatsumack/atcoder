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

class ETraveler {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<pair<int, int>> v(N);
        REP(i, N) {
            int x, c;
            cin >> x >> c;
            v[i] = {c, x};
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> LR;
        int prev = v[0].first;
        int l = v[0].second;
        int r = v[0].second;
        REP(i, v.size()) {
            if (v[i].first != prev) {
                LR.emplace_back(l, r);
                l = r = v[i].second;
            } else {
                l = min(l, v[i].second);
                r = max(r, v[i].second);
            }
            prev = v[i].first;
        }
        LR.emplace_back(l, r);
        LR.emplace_back(0, 0);
        vector<vector<int>> dp(LR.size() + 1, vector<int>(2, INF));
        dp[0][0] = dp[0][1] = 0;
        REP(i, LR.size()) {
            int L = LR[i].first;
            int R = LR[i].second;
            int PL = i > 0 ? LR[i - 1].first : 0;
            int PR = i > 0 ? LR[i - 1].second : 0;
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + abs(PL - R) + R - L);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + abs(PR - R) + R - L);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + abs(PL - L) + R - L);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + abs(PR - L) + R - L);
        }
        cout << min(dp[LR.size()][0], dp[LR.size()][1]) << endl;
    }
};
