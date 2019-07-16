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

class BEvenDegrees {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;
    vector<int> out;
    vector<P> ans;
    set<int> visited;
    set<P> path;

    void dfs(int v, int p) {
        visited.insert(v);

        int num = 0;
        REP(i, G[v].size()) {
            int to = G[v][i];
            if (to == p) continue;

            if (visited.count(to)) {
                if (path.count({v, to}) || path.count({to, v})) continue;
                ans.emplace_back(v, to);
                path.insert({v, to});
                out[v]++;
            } else {
                dfs(to, v);
            }
        }

        if (p != -1) {
            if (out[v] % 2 == 1) {
                ans.emplace_back(v, p);
                path.insert({v, p});
            } else {
                ans.emplace_back(p, v);
                path.insert({p, v});
                out[p]++;
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        G = vector<vector<int>>(N);
        out = vector<int>(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        if (M % 2 == 1) {
            cout << -1 << endl;
            return;
        }

        dfs(0, -1);

        REP(i, ans.size()) {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }
};
