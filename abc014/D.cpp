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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

struct LCA {
    static const int MAX_V = 100100;
    static const int MAX_LOG_V = 21;

    vector<int> G[MAX_V];

    int parent[MAX_LOG_V][MAX_V];
    int depth[MAX_V];

    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (int i = 0; i < G[v].size(); i++) {
            if (G[v][i] != p) dfs(G[v][i], v, d + 1);
        }
    }

    void init(int root, int V) {
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < MAX_LOG_V; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < MAX_LOG_V; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;

        for (int k = MAX_LOG_V - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }
};

int N, Q;
LCA lca;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    REP(i, N - 1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        lca.G[x].push_back(y);
        lca.G[y].push_back(x);
    }

    lca.init(1, N);

    cin >> Q;
    REP(i, Q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int p = lca.get(a, b);
        cout << lca.depth[a] + lca.depth[b] - 2 * lca.depth[p] + 1 << endl;
    }

    return 0;
}
