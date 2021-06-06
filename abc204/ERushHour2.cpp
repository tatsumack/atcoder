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

class ERushHour2 {
public:
    vector<int> dist;
    vector<vector<tuple<int, int, int>>> G;

    int N, M;

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
                int to, c, d;
                tie(to, c, d) = G[v][i];
                int wait = sqrt(d);
                if (wait > 0) {
                    if (d / (wait + 1) < d / wait) wait++;
                }
                int next;
                if (cost + 1 > wait) {
                    next = cost + c + d / (cost + 1);
                } else {
                    next = cost + c + d / wait + wait - (cost + 1);
                }
                if (dist[to] > next) {
                    dist[to] = next;
                    pq.push({next, to});
                }
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        dist = vector<int>(N, INF);
        G.resize(N);
        REP(i, M) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--;
            G[a].emplace_back(b, c, d);
            G[b].emplace_back(a, c, d);
        }
        dijkstra(0);
        cout << (dist[N - 1] == INF ? -1 : dist[N - 1]) << endl;
    }
};
