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

struct bfs_euler_tour {
    int N;
    std::vector<std::vector<int>> G;
    std::vector<int> in;
    std::vector<int> out;
    std::vector<int> para;
    std::vector<int> inv_para;
    std::vector<int> dep;
    std::vector<int> par;
    std::vector<int> start;
    int cnt;
    int D;

    bfs_euler_tour(int N) : N(N), G(N), in(N), out(N), para(N, -1), inv_para(N, -1), dep(N), par(N) {}

    void add_edge(int a, int b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }

    void dfs(int v, int f, int depth) {
        D = std::max(D, depth);
        par[v] = f;
        dep[v] = depth;
        in[v] = cnt++;
        for (auto t: G[v]) {
            if (t == f) continue;
            dfs(t, v, depth + 1);
        }
        out[v] = cnt;
    }

    void build(int r) {
        cnt = 0;
        D = 0;
        dfs(r, -1, 0);
        D++;

        cnt = 0;
        std::vector<int> que(N);
        int ql = 0;
        int qr = 0;
        que[qr++] = r;
        start.resize(D + 1);

        for (int d = 0; ql < qr; d++) {
            int r = qr;
            start[d] = cnt;
            while (ql < r) {
                int v = que[ql++];
                inv_para[v] = cnt;
                para[cnt++] = v;
                for (auto t: G[v]) {
                    if (in[v] < in[t]) {
                        que[qr++] = t;
                    }
                }
            }
        }
        start[D] = cnt;
    }

    int para_lower_bound(int l, int r, int i) {
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (i <= in[para[m]]) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }

    std::pair<int, int> range(int v, int d) {
        if (dep[v] + d < D) {
            int l = start[dep[v] + d];
            int r = start[dep[v] + d + 1];
            return {para_lower_bound(l - 1, r, in[v]), para_lower_bound(l - 1, r, out[v])};
        } else {
            return {0, 0};
        }
    }
};

class ECountDescendants {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        bfs_euler_tour B(N);
        REP(i, N - 1) {
            int p;
            cin >> p;
            p--;
            B.add_edge(i + 1, p);
        }
        B.build(0);

        int Q;
        cin >> Q;
        REP(i, Q) {
            int u, d;
            cin >> u >> d;
            u--;
            if (d < B.dep[u]) {
                cout << 0 << endl;
                continue;
            }
            auto kv = B.range(u, d - B.dep[u]);
            cout << kv.second - kv.first << endl;
        }
    }
};
