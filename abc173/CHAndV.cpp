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

class CHAndV {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, K;
        cin >> H >> W >> K;
        vector<vector<char>> c(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> c[i][j];

        int res = 0;
        REP(si, 1 << H) {
            REP(sj, 1 << W) {
                int num = 0;
                REP(i, H) {
                    REP(j, W) {
                        if ((si >> i) & 1) continue;
                        if ((sj >> j) & 1) continue;
                        if (c[i][j] == '#') num++;
                    }
                }
                if (num == K) res++;
            }
        }
        cout << res << endl;
    }
};
