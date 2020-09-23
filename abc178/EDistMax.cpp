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

class EDistMax {
public:
    int N;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        int minP = INF;
        int minM = INF;
        int maxP = -INF;
        int maxM = -INF;

        int res = 0;
        REP(i, N) {
            int x, y;
            cin >> x >> y;
            int p = x + y;
            int m = x - y;
            if (i > 0) {
                res = max(res, p - minP);
                res = max(res, -m + maxM);
                res = max(res, m - minM);
                res = max(res, -p + maxP);
            }

            minP = min(minP, p);
            minM = min(minM, m);
            maxP = max(maxP, p);
            maxM = max(maxM, m);
        }
        cout << res << endl;
    }
};
