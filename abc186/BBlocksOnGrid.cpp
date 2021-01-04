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

class BBlocksOnGrid {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<int>> A(H, vector<int>(W));
        int m = INF;
        REP(i, H) REP(j, W) {
            cin >> A[i][j];
            m = min(m, A[i][j]);
        }
        int res = 0;
        REP(i, H) REP(j, W) {
            res += A[i][j] - m;
        }
        cout << res << endl;
    }
};
