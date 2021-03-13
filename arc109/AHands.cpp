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

class AHands {
public:
    int sa, gb, x, y;

    vector<int> dist;
    vector<vector<tuple<int, int>>> G;

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
                int to, cost;
                tie(to, cost) = G[v][i];
                if (dist[v] + cost < dist[to]) {
                    dist[to] = dist[v] + cost;
                    pq.push({dist[to], to});
                }
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> sa >> gb >> x >> y;
        sa--, gb--;
        gb += 100;
        G.resize(100 * 100);
        dist = vector<int>(100 * 100, INF);
        REP(a, 100) {
            int b = 100 + a;
            G[a].emplace_back(b, x);
            if (a - 1 >= 0) {
                G[a].emplace_back(b - 1, x);
                G[a].emplace_back(a - 1, y);
            }
            if (a + 1 < 100) {
                G[a].emplace_back(a + 1, y);
            }

            G[b].emplace_back(a, x);
            if (a - 1 >= 0) {
                G[b].emplace_back(b - 1, y);
            }
            if (a + 1 < 100) {
                G[b].emplace_back(a + 1, x);
                G[b].emplace_back(b + 1, y);
            }
        }
        dijkstra(sa);
        cout << dist[gb] << endl;
    }
};
