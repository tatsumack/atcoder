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

struct MAX_FLOW {
    struct edge {
        int to, cap, rev;

        edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> G;
    vector<bool> used;
    int sz;

    MAX_FLOW(int size) {
        sz = size;
        G.resize(sz);
        used.resize(sz);
    }

    void add_edge(int from, int to, int cap) {
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, 0, G[from].size() - 1);
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            used.clear();
            used.resize(sz);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

class FLotusLeaves {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;

        MAX_FLOW mf(H + W + 2);
        int s = H + W;
        int t = s + 1;
        REP(i, H) {
            REP(j, W) {
                char c;
                cin >> c;
                if (c != '.') {
                    mf.add_edge(i, j + H, 1);
                    mf.add_edge(j + H, i, 1);
                }
                if (c == 'S') {
                    mf.add_edge(s, i, INF);
                    mf.add_edge(s, j + H, INF);
                }
                if (c == 'T') {
                    mf.add_edge(i, t, INF);
                    mf.add_edge(j + H, t, INF);
                }
            }
        }
        int val = mf.max_flow(s, t);
        if (val >= INF) val = -1;
        cout << val << endl;
    }
};
