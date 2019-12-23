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


class f {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }
    vector<vector<int>> G;
    void dfs(vector<int>& dist, int v, int p, int d) {
        dist[v] = d;
        for (int to : G[v]) {
            if (to == p) continue;
            dfs(dist, to, v, d + 1);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, u, v;
        cin >> n >> u >> v;
        u--, v--;

        G.resize(n);
        REP(i, n-1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> distu(n), distv(n);
        dfs(distu, u, -1, 0);
        dfs(distv, v, -1, 0);
        int res = -1;
        REP(i, n) {
            if (distu[i] < distv[i]) {
                res = max(res, distv[i] - 1);
            }
        }

        cout << res << endl;
    }
};
