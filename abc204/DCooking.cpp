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

class DCooking {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> T(N);

        int sum = 0;
        REP(i, N) {
            cin >> T[i];
            sum += T[i];
        }
        vector<bool> dp(100005);
        dp[0] = true;

        int res = sum;
        REP(i, N) {
            vector<bool> next = dp;
            REP(j, 100005) {
                if (!dp[j]) continue;
                next[j + T[i]] = true;
                res = min(res, max(j + T[i], sum - (j + T[i])));
            }
            swap(dp, next);
        }
        cout << res << endl;
    }
};
