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

class ARangeFlipFindRoute {
public:
    map<pair<int, int>, int> memo;
    int H, W;
    vector<vector<char>> s;

    int dfs(int x, int y) {
        if (memo.count({x, y})) return memo[{x, y}];
        if (x == H - 1 && y == W - 1) {
            return s[x][y] == '#' ? 1 : 0;
        }

        int res = INF;
        if (x + 1 < H) {
            int tmp = dfs(x+1, y);
            if (s[x][y] == '#' && s[x + 1][y] == '.') tmp++;
            res = min(res, tmp);
        }
        if (y + 1 < W) {
            int tmp = dfs(x, y + 1);
            if (s[x][y] == '#' && s[x][y + 1] == '.') tmp++;
            res = min(res, tmp);
        }
        return memo[{x, y}] = res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W;
        s = vector<vector<char>>(H, vector<char>(W, '.'));
        REP(i, H) {
            REP(j, W) {
                cin >> s[i][j];
            }
        }
        int res = dfs(0, 0);
        cout << res << endl;
    }
};
