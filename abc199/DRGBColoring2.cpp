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

class DRGBColoring2 {
public:

    vector<vector<int>> G;
    vector<int> V, color;
    vector<bool> visit;
    int w = 0;

    void dfs(int v) {
        visit[v] = true;
        V.push_back(v);
        for (auto to : G[v]) {
            if (visit[to]) continue;
            dfs(to);
        }
    }

    void dfs2(int i) {
        if (i == V.size()) {
            w++;
            return;
        }
        set<int> c;
        c.insert(1);
        c.insert(2);
        c.insert(3);
        for (auto to : G[V[i]]) {
            c.erase(color[to]);
        }
        for (auto cc :c) {
            color[V[i]] = cc;
            dfs2(i + 1);
            color[V[i]] = 0;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        G.resize(N);
        UnionFind uf(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            uf.unite(a, b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int res = 1;
        REP(i, N) {
            if (uf.find(i) != i) continue;
            V.clear();
            visit = vector<bool>(N);
            dfs(i);
            w = 0;
            color = vector<int>(N);
            dfs2(0);
            res *= w;
        }
        cout << res << endl;
    }
};
