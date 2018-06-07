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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

struct edge
{
    int to, cost;
    edge(int _to, int _cost) : to(_to), cost(_cost) {}
    edge() {}
};

int N, M, T;
int A[100005];
vector<edge> G[100005];
vector<edge> R[100005];
int d[100005];
int r[100005];

typedef pair<int, int> P;
void dijkstra(int s, int n, vector<edge> E[], int a[])
{
    priority_queue<P, vector<P>, greater<P> > que;
    REP(i, n+1)
    a[i] = INF;
    a[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (a[v] < p.first)
            continue;
        for (int i = 0; i < E[v].size(); ++i)
        {
            edge e = E[v][i];
            if (a[e.to] > a[v] + e.cost)
            {
                a[e.to] = a[v] + e.cost;
                que.push(P(a[e.to], e.to));
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;
    REPS(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(edge(b, c));
        R[b].push_back(edge(a, c));
    }

    dijkstra(1, N, G, d);
    dijkstra(1, N, R, r);

    int ans = 0;
    REPS(i, N)
    {
        if (d[i] == INF || r[i] == INF) continue;
        ans = max(ans, (T - d[i] - r[i]) * A[i]);
    }
    cout << ans << endl;

    return 0;
}
