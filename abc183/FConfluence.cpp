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

class FConfluence {
public:
    vector<int> C;
    vector<map<int, int>> v;

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
        void unite(int x, int y, vector<map<int, int>>& v) {
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

            auto& mx = v[x];
            auto& my = v[y];
            if (mx.size() < my.size()) {
                for (auto kv : mx) {
                    my[kv.first] += kv.second;
                }
                if (rank[x] >= rank[y]) {
                    swap(v[x], v[y]);
                }
            } else {
                for (auto kv : my) {
                    mx[kv.first] += kv.second;
                }
                if (rank[x] < rank[y]) {
                    swap(v[x], v[y]);
                }
            }
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int size(int x) { return vsize[find(x)]; }
    };

    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N >> Q;
        C.resize(N);
        v.resize(N);
        REP(i, N) cin >> C[i];
        REP(i, N) {
            v[i][C[i]] = 1;
        }

        UnionFind uf(N+5);
        REP(i, Q) {
            int type, a, b;
            cin >> type >> a >> b;
            if (type == 1) {
                a--, b--;
                uf.unite(a, b, v);
            } else {
                a--;
                cout << v[uf.find(a)][b] << endl;
            }
        }
    }
};
