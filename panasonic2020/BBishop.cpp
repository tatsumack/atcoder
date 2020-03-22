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

class BBishop {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        if (H == 1 || W == 1) {
            cout << 1 << endl;
            return;
        }
        int row1 = (W + 1) / 2;
        int row2 = W / 2;
        int res = row1 * (H / 2) + row2 * (H / 2);
        if (H % 2 == 1) res += row1;
        cout << res << endl;
    }
};
