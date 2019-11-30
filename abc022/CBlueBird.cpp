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

class CBlueBird {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> dist(n, vector<int>(n, INF));
        REP(i, n) dist[i][i] = 0;
        vector<P> dfrom0;
        REP(i, m) {
            int u, v, l;
            cin >> u >> v >> l;
            u--, v--;
            if (u == 0 || v == 0) {
                dfrom0.emplace_back(max(u, v), l);
                continue;
            }
            dist[u][v] = l;
            dist[v][u] = l;
        }

        REP(k, n) REP(i, n) REP(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int res = INF;
        REP(i, dfrom0.size()) {
            FOR(j, i + 1, dfrom0.size() - 1) {
                int left = dfrom0[i].first;
                int left_cost = dfrom0[i].second;
                int right = dfrom0[j].first;
                int right_cost = dfrom0[j].second;

                res = min(res, left_cost + right_cost + dist[left][right]);
            }
        }
        if (res >= INF) res = -1;
        cout << res << endl;
    }
};
