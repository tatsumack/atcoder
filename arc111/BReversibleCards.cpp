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

class BReversibleCards {
public:
    vector<vector<int>> G;
    vector<int> visit;

    bool dfs(int v, int p) {
        if (visit[v]) return false;
        visit[v] = true;
        for (auto to : G[v]) {
            if (to == p) continue;
            bool ok = dfs(to, v);
            if (!ok) return false;
        }
        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(400005);
        visit.resize(400005);
        UnionFind uf(400005);
        set<int> s;
        REP(i, N) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
            uf.unite(a, b);
            s.insert(a);
            s.insert(b);
        }

        int res = 0;
        for (auto i : s) {
            int root = uf.find(i);
            if (visit[root]) continue;
            if (uf.size(root) == 1) {
                visit[root] = true;
                res++;
                continue;
            }

            if (dfs(root, -1)) {
                res += uf.size(root) - 1;
            } else {
                res += uf.size(root);
            }
        }

        cout << res << endl;
    }
};
