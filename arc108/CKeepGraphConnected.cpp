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

class CKeepGraphConnected {
public:
    vector<int> res;
    vector<vector<P>> G;

    void dfs(int n, int p) {
        for (auto to: G[n]) {
            if (to.first == p) continue;
            if (res[n] == to.second) {
                res[to.first] = to.second == 1 ? 2 : 1;
            } else {
                res[to.first] = to.second;
            }
            dfs(to.first, n);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        G.resize(N);
        UnionFind uf(N);

        REP(i, M) {
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            if (uf.same(u, v)) continue;
            uf.unite(u, v);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }
        res.resize(N);
        res[0] = 1;
        dfs(0, -1);
        REP(i, N) {
            cout << res[i] << endl;
        }
    }
};
