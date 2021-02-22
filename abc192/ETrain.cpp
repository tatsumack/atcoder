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

class ETrain {
public:
    int N, M, X, Y;
    vector<int> dist;
    vector<vector<tuple<int, int, int>>> G;

    void dijkstra(int s) {
        dist[s] = 0;
        priority_queue<P, vector<P>, greater<>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            int v, cost;
            tie(cost, v) = pq.top();
            pq.pop();
            if (dist[v] < cost) continue;
            dist[v] = cost;
            REP(i, G[v].size()) {
                int to, t, k;
                tie(to, t, k) = G[v][i];
                int wait = cost % k == 0 ? 0 : k - (cost % k);
                int next = cost + t + wait;
                if (dist[to] > next) {
                    dist[to] = next;
                    pq.push({next, to});
                }
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> X >> Y;
        X--, Y--;
        dist = vector<int>(N, INF);
        G.resize(N);
        REP(i, M) {
            int a, b, t, k;
            cin >> a >> b >> t >> k;
            a--, b--;
            G[a].push_back({b, t, k});
            G[b].push_back({a, t, k});
        }
        dijkstra(X);
        if (dist[Y] >= INF) {
            cout << -1 << endl;
            return;
        }
        cout << dist[Y] << endl;
    }
};
