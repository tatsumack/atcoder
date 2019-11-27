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

class DColoringEdgesOnTree {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N;
    vector<vector<P>> G;
    vector<int> color;

    void dfs(int v, int p, int n) {
        int c = 1;
        REP(i,G[v].size()) {
            int child, idx;
            tie(child, idx) = G[v][i];
            if (child == p) continue;

            if (c == n) c++;
            color[idx] = c;

            dfs(child, v, c);
            c++;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        G.resize(N), color.resize(N - 1);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back({b, i});
            G[b].push_back({a, i});
        }

        dfs(0, -1, 0);

        int res = -1;
        REP(i, color.size()) {
            res = max(res, color[i]);
        }
        cout << res << endl;
        REP(i, color.size()) {
            cout << color[i] << endl;
        }
    }
};
