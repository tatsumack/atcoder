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

class ABC {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int L, R;
            cin >> L >> R;
            if (L * 2 > R) {
                cout << 0 << endl;
                continue;
            }
            int res = 0;
            int k = (R - L) - L + 1;
            res += (1 + k) * k / 2;
            cout << res << endl;
        }
    }
};
