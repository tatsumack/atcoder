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

class DDiceInLine {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> p(N);
        REP(i, N) cin >> p[i];

        vector<int> sum(1001);
        FOR(i, 1, 1000) sum[i] = i + sum[i - 1];

        int r = 0;
        double cur = 0;
        while (r < K - 1) {
            cur += (double) sum[p[r]] / (double) p[r];
            r++;
        }

        double res = 0;
        REP(l, N - K + 1) {
            if (r >= N) break;
            cur += (double) sum[p[r]] / (double) p[r];
            res = max(res, cur);
            cur -= (double) sum[p[l]] / (double) p[l];
            r++;
        }
        fcout << res << endl;
    }
};
