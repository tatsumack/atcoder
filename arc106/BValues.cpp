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

class BValues {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N), b(N);
        REP(i, N) cin >> a[i];
        REP(i, N) cin >> b[i];

        UnionFind uf(N);
        REP(i, M) {
            int c, d;
            cin >> c >> d;
            c--, d--;
            uf.unite(c, d);
        }

        map<int, int> ma, mb;
        REP(i, N) {
            ma[uf.find(i)] += a[i];
            mb[uf.find(i)] += b[i];
        }

        bool ok = true;
        for (auto kv : ma) {
            if (kv.second != mb[kv.first]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
};
