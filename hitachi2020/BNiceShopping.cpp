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

struct LCA {
    static const int MAX_LOG_V = 21;

    vector<vector<int>> G;
    vector<vector<int>> parent;
    vector<int> depth;

    LCA(int size) {
        G = vector<vector<int>>(size);
        parent = vector<vector<int>>(MAX_LOG_V, vector<int>(size));
        depth = vector<int>(size);
    }


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
class BNiceShopping {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B, M;
        cin >> A >> B >> M;
        vector<int> a(A), b(B), x(M), y(M), c(M);
        REP(i, A) cin >> a[i];
        REP(i, B) cin >> b[i];
        REP(i, M) {
            cin >> x[i] >> y[i] >> c[i];
            x[i]--, y[i]--;
        }

        int ma = INF;
        int mb = INF;
        REP(i, A) {
            ma = min(ma, a[i]);
        }
        REP(i, B) {
            mb = min(mb, b[i]);
        }
        int res = ma + mb;
        REP(i, M) {
            res = min(res, a[x[i]] + b[y[i]] - c[i]);
        }
        cout << res << endl;
    }
};
