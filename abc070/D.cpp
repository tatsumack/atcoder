#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

struct edge
{
    int to, cost;
    edge(int _to, int _cost) : to(_to), cost(_cost) {}
    edge() {}
};
typedef pair<int, int> P;

int V;
vector<edge> G[100003];
int d[100003];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    REP(i, V+1) d[i] = INF;
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int Q, K;

signed main()
{
    cin >> V;
    REP(i, V-1)
    {
        int a, b, c;
        cin >> a >> b >> c;

        G[a].push_back(edge(b,c));
        G[b].push_back(edge(a,c));
    }

    cin >> Q >> K;
    dijkstra(K);
    REP(i, Q)
    {
        int x, y;
        cin >> x >> y;
        int ans = d[x] + d[y];
        printf("%lld\n", ans);
    }

    return 0;
}
