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

struct edge {
    int to, cost;

    edge(int to, int cost) : to(to), cost(cost) {}
};

vector<int> X;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;
    vector<int> vsum;

    UnionFind(int size) : par(size), rank(size), vsize(size), vsum(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
            vsum[i] = X[i];
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
        vsum[x] += vsum[y];
        vsum[y] = vsum[x];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return vsize[find(x)]; }

    int sum(int x) { return vsum[find(x)]; }
};

class EWeightsOnVerticesAndEdges {
public:
    set<int> ok, visited;
    map<P, int> id;
    int N, M;
    vector<vector<edge>> G;

    void dfs(int v, int p, int c) {
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            if (e.cost > c) continue;
            int a = v;
            int b = e.to;
            if (a > b) swap(a, b);
            if (visited.count(id[{a, b}])) continue;
            visited.insert(id[{a, b}]);
            dfs(e.to, v, c);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        X.resize(N), G.resize(N);
        REP(i, N) cin >> X[i];

        vector<pair<int, P>> v(M);
        REP(i, M) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            v[i] = {c, {a, b}};
            G[a].emplace_back(b, c);
            G[b].emplace_back(a, c);
            id[{a, b}] = i;
        }
        sort(v.begin(), v.end());

        UnionFind uf(N);

        REP(i, v.size()) {
            auto kv = v[i];
            int a, b, c;
            tie(a, b) = kv.second;
            c = kv.first;

            uf.unite(a, b);
            int val = uf.sum(a);
            if (c <= val) {
                ok.insert(id[{a, b}]);
            }
        }

        REV(i, v.size() - 1, 0) {
            auto kv = v[i];
            int a, b, c;
            tie(a, b) = kv.second;
            c = kv.first;

            if (visited.count(id[{a, b}])) continue;
            if (ok.count(id[{a, b}])) {
                dfs(a, -1, c);
            }
        }
        cout << M - visited.size() << endl;
    }
};
