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

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;

    UnionFind(int size) : par(size), rank(size), vsize(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        vsize[x] += vsize[y];
        vsize[y] = vsize[x];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return vsize[find(x)]; }
};

struct LCA {
    static const int MAX_V = 100005;
    static const int MAX_LOG_V = 21;

    vector<vector<P>> G;

    vector<bool> used;
    vector<vector<int>> parent;
    vector<vector<int>> cost;
    vector<int> depth;

    LCA(int size) {
        G = vector<vector<P>>(size);
        used = vector<bool>(size);
        parent = vector<vector<int>>(MAX_LOG_V, vector<int>(size));
        cost = vector<vector<int>>(MAX_LOG_V, vector<int>(size));
        depth = vector<int>(size);
    }

    void dfs(int v, int c, int p, int d) {
        used[v] = true;
        parent[0][v] = p;
        cost[0][v] = c;
        depth[v] = d;
        for (int i = 0; i < G[v].size(); i++) {
            if (G[v][i].first != p) dfs(G[v][i].first, G[v][i].second, v, d + 1);
        }
    }

    void init(int V) {
        REP(root, V) {
            if (used[root]) continue;
            dfs(root, 0, -1, 0);
        }
        for (int k = 0; k + 1 < MAX_LOG_V; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                    cost[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                    cost[k + 1][v] = max(cost[k][v], cost[k][parent[k][v]]);
                }
            }
        }
    }

    int get(int u, int v) {
        int res = 0;

        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < MAX_LOG_V; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                res = max(res, cost[k][v]);
                v = parent[k][v];
            }
        }
        if (u == v) return res;

        for (int k = MAX_LOG_V - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                res = max({res, cost[k][u], cost[k][v]});
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return max({res, cost[0][u], cost[0][v]});
    }
};


class HUnionSets {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;

        LCA lca(N);
        UnionFind uf(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            if (uf.same(a, b)) continue;
            uf.unite(a, b);
            lca.G[a].emplace_back(b, i + 1);
            lca.G[b].emplace_back(a, i + 1);
        }
        lca.init(N);

        int Q;
        cin >> Q;
        REP(i, Q) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (!uf.same(x, y)) {
                cout << -1 << endl;
                continue;
            }

            cout << lca.get(x, y) << endl;
        }
    }
};
