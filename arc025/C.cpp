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

class C {
public:
    int N, M, R, T;
    struct edge
    {
        int to, cost;
        edge(int _to, int _cost) : to(_to), cost(_cost) {}
        edge() {}
    };
    vector<vector<edge>> G;
    vector<int> dijkstra(int s)
    {
        vector<int> d(N);
        priority_queue<P, vector<P>, greater<P> > que;
        REP(i, N) d[i] = INF;
        d[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top(); que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (auto e : G[v]) {
                if (d[e.to] > d[v] + e.cost)
                {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }

        return d;
    }
    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> R >> T;
        G.resize(N);
        REP(i, M) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            c *= T;
            G[a].emplace_back(b, c);
            G[b].emplace_back(a, c);
        }

        int res = 0;
        REP(n, N) {
            auto d = dijkstra(n);
            sort(d.begin(), d.end());
            REP(i, d.size()) {
                if (i == 0) continue;
                int len = d[i] * R / T;
                int idx = upper_bound(d.begin(), d.end(), len) - d.begin();
                if (idx > i) {
                    res += N - idx;
                } else {
                    res += N - idx - 1;
                }
            }
        }
        cout << res << endl;
    }
};
