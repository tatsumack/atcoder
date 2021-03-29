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

class BVisibility {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, X, Y;
        cin >> H >> W >> X >> Y;
        X--, Y--;
        vector<vector<char>> S(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> S[i][j];

        int res = 0;
        int x = X;
        while (x + 1 < H && S[x + 1][Y] == '.') res++, x++;
        x = X;
        while (x - 1 >= 0 && S[x - 1][Y] == '.') res++, x--;
        int y = Y;
        while (y + 1 < W && S[X][y + 1] == '.') res++, y++;
        y = Y;
        while (y - 1 >= 0 && S[X][y - 1] == '.') res++, y--;
        cout << res + 1 << endl;
    }
};
