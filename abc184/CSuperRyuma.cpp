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

class CSuperRyuma {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int rx, ry, gx, gy;
        cin >> rx >> ry >> gx >> gy;
        if (rx == gx && ry == gy) {
            cout << 0 << endl;
            return;
        }
        if ((rx + ry == gx + gy) || (rx - ry == gx - gy) || abs(rx - gx) + abs(ry - gy) <= 3) {
            cout << 1 << endl;
            return;
        }
        if ((rx + ry) % 2 == (gx + gy) % 2) {
            cout << 2 << endl;
            return;
        }
        for (int i = rx - 2; i <= rx + 2; i++) {
            for (int j = ry - 2; j <= ry + 2; j++) {
                if ((i + j) == (gx + gy)) {
                    cout << 2 << endl;
                    return;
                }
                if ((i - j) == (gx - gy)) {
                    cout << 2 << endl;
                    return;
                }
            }
        }
        int dx[] = {-3, 0, 0, 3};
        int dy[] = {0, -3, 3, 0};
        REP(k, 4) {
            int tx = rx + dx[k];
            int ty = ry + dy[k];
            if (abs(gx - tx) + abs(gy - ty) <= 3) {
                cout << 2 << endl;
                return;
            }
        }
        cout << 3 << endl;
    }
};
