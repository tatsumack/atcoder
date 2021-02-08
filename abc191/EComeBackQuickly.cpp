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

typedef pair<int, int> PP;

class EComeBackQuickly {
public:
    int N, M;
    map<int, tuple<int, int, int>> id;

    int dijkstra(int s, int g, int used) {
        priority_queue<PP, vector<PP>, greater<PP> > que;
        vector<int> dist(N);
        REP(i, N) {
            dist[i] = INF;
        }
        que.push({0, s});

        while (!que.empty()) {
            PP p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (auto e : G[v]) {
                if (e == used) continue;
                int from, to, cost;
                tie(from, to, cost) = id[e];
                if (dist[to] > p.first + cost) {
                    dist[to] = p.first + cost;
                    que.push({dist[to], to});
                }
            }
        }
        return dist[g];
    }

    vector<vector<int>> G;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        G.resize(N);
        REP(i, M) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            G[a].push_back(i);
            id[i] = {a, b, c};
        }

        vector<int> res(N, INF);
        REP(i, M) {
            int from, to, cost;
            tie(from, to, cost) = id[i];
            if (from == to) {
                res[from] = min(res[from], cost);
            } else {
                int d = dijkstra(to, from, i);
                res[from] = min(res[from], d + cost);
            }
        }
        REP(i, N) {
            if (res[i] >= INF) {
                cout << -1 << endl;
            } else {
                cout << res[i] << endl;
            }
        }
    }
};
