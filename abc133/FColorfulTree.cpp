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
};

class FColorfulTree {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<vector<int>>> G;
    vector<int> dist, cnum, csum;
    vector<vector<int>> C;
    vector<map<int, int>> num, sum;

    void dfs(int v, int p = -1) {
        for (auto c : C[v]) {
            num[v][c] = cnum[c];
            sum[v][c] = csum[c];
        }

        REP(i, G[v].size()) {
            int to = G[v][i][0];
            int c = G[v][i][1];
            int d = G[v][i][2];
            if (to == p) continue;

            dist[to] = dist[v] + d;

            cnum[c]++;
            csum[c] += d;
            dfs(to, v);
            cnum[c]--;
            csum[c] -= d;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N >> Q;

        dist.resize(N);
        G.resize(N);
        C.resize(N);
        cnum.resize(N);
        csum.resize(N);
        vector<int> X(Q), Y(Q), U(Q), V(Q), L(Q);
        num = vector<map<int, int>>(N);
        sum = vector<map<int, int>>(N);
        LCA lca(N);

        REP(i, N - 1) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--;
            G[a].push_back({b, c, d});
            G[b].push_back({a, c, d});
            lca.G[a].push_back(b);
            lca.G[b].push_back(a);
        }
        lca.init(0, N);

        REP(i, Q) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            x--, u--, v--;
            X[i] = x;
            Y[i] = y;
            U[i] = u;
            V[i] = v;
            int l = lca.get(u, v);
            L[i] = l;
            C[l].push_back(x);
            C[u].push_back(x);
            C[v].push_back(x);
        }

        dfs(0);

        REP(i, Q) {
            int u = U[i];
            int v = V[i];
            int l = L[i];
            int x = X[i];
            int y = Y[i];
            int d = dist[u] + dist[v] - 2 * dist[l];
            int n = num[u][x] + num[v][x] - 2 * num[l][x];
            int s = sum[u][x] + sum[v][x] - 2 * sum[l][x];
            cout << d - s + n * y << endl;
        }
    }
};
