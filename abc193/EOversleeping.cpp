#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class EOversleeping {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int X, Y, P, Q;
            cin >> X >> Y >> P >> Q;
            int res = INF;
            for (int i = X; i < X + Y; i++) {
                for (int j = P; j < P + Q; j++) {
                    int y, z;
                    tie(y, z) = atcoder::crt({i, j}, {2 * (X + Y), P + Q});
                    if (y == 0) continue;
                    res = min(res, y);
                }
            }
            if (res == INF) {
                cout << "infinity" << endl;
                continue;
            }
            cout << res << endl;
        }

    }
};
