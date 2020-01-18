#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;


int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

class DMazeMaster {
public:

    vector<vector<char>> G;
    int H, W;
    set<pair<P, P>> found;

    int calc(int sx, int sy) {
        if (G[sx][sy] == '#') return 0;

        queue<pair<P, int>> q;
        set<P> used;
        q.push({{sx, sy}, 0});
        int res = 0;
        while (!q.empty()) {
            auto kv = q.front();
            q.pop();
            P pos = kv.first;
            int d = kv.second;
            res = max(res, d);
            if (used.count(pos)) continue;
            used.insert(pos);
            REP(i, 4) {
                int nx = pos.first + dx[i];
                int ny = pos.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (G[nx][ny] == '#') continue;
                if (used.count({nx, ny})) continue;
                q.push({{nx, ny}, d + 1});
            }
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W;
        G = vector<vector<char>>(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> G[i][j];

        int res = 0;
        REP(si, H) {
            REP(sj, W) {
                res = max(res, calc(si, sj));
            }
        }
        cout << res << endl;

    }
};
