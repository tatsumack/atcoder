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

class B {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;
    vector<int> h;

    pair<bool, int> dfs(int v, int p) {
        int res = 0;
        bool found = h[v];
        REP(i, G[v].size()) {
            int to = G[v][i];
            if (to == p) continue;

            auto kv = dfs(to, v);
            if (!kv.first) continue;
            found = true;
            res += kv.second + 2;
        }

        return {found, res};
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, x;
        cin >> n >> x;
        x--;
        h.resize(n);
        REP(i, n) cin >> h[i];
        G.resize(n);
        REP(i, n - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        auto ans = dfs(x, -1);
        cout << ans.second << endl;
    }
};
