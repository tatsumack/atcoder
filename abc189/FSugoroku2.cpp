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

class FSugoroku2 {
public:
    vector<int> furidashi;
    int N, M, K;

    double calc(double m) {
        vector<double> dp(N + M + 5);
        double sum = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (furidashi[i] > 0) {
                dp[i] = m;
            } else {
                dp[i] = 1 + sum / M;
            }
            sum += dp[i];
            sum -= dp[i+M];
        }
        return dp[0];
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> K;
        furidashi.resize(N+1);
        bool ok = true;
        int cur = 0;
        int prev = -INF;
        REP(i, K) {
            int a;
            cin >> a;
            furidashi[a] = 1;
            if (a - prev == 1) {
                cur++;
            } else {
                cur = 1;
            }
            if (cur >= M) {
                ok = false;
            }
            prev = a;
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }
        double l = 0;
        double r = INF;
        REP(i, 300) {
            double m = (l + r) / 2;
            if (calc(m) > m) {
                l = m;
            } else {
                r = m;
            }
        }
        fcout << l << endl;
    }
};
