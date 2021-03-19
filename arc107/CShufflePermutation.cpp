#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

using mint = atcoder::modint998244353;

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

class CShufflePermutation {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> A(N, vector<int>(N));
        REP(i, N) {
            REP(j, N) {
                cin >> A[i][j];
            }
        }
        UnionFind uf(N * 2 + 1);
        REP(i, N) {
            for (int j = i + 1; j < N; j++) {
                bool rok = true;
                bool cok = true;
                REP(k, N) {
                    if (A[i][k] + A[j][k] > K) {
                        rok = false;
                    }
                    if (A[k][i] + A[k][j] > K) {
                        cok = false;
                    }
                }
                if (rok) {
                    uf.unite(i, j);
                }
                if (cok) {
                    uf.unite(i + N, j + N);
                }
            }
        }
        set<int> found;
        mint r = 1;
        REP(i, N) {
            if (found.count(uf.find(i))) continue;
            found.insert(uf.find(i));
            int n = uf.size(i);
            mint tmp = 1;
            while (n > 0) {
                tmp *= n;
                n--;
            }
            r *= tmp;
        }
        mint c = 1;
        REP(i, N) {
            if (found.count(uf.find(i + N))) continue;
            found.insert(uf.find(i + N));
            int n = uf.size(i + N);
            mint tmp = 1;
            while (n > 0) {
                tmp *= n;
                n--;
            }
            c *= tmp;
        }
        mint res = r * c;
        cout << res.val() << endl;
    }
};
