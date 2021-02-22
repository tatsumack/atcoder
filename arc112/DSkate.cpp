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

class DSkate {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        UnionFind uf(H * W);
        REP(i, H) {
            REP(j, W) {
                char c;
                cin >> c;
                if (c != '#') continue;
                uf.unite(i, H + j);
            }
        }
        uf.unite(0, H + 0);
        uf.unite(0, H + W);
        uf.unite(H - 1, H + 0);
        uf.unite(H - 1, H + W - 1);
        set<int> r, c;
        REP(i, H) {
            r.insert(uf.find(i));
        }
        REP(j, W) {
            c.insert(uf.find(j + H));
        }
        cout << min((int) r.size() - 1, (int) c.size() - 1) << endl;
    }
};
