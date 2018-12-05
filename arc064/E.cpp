
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

struct Circle {
    int x, y, r;
};
typedef pair<int, pair<int, int>> PP;

int sx, sy, xx, yy;

typedef pair<double, int> P;
struct edge
{
    int to;
    double cost;
    edge(int _to, double _cost) : to(_to), cost(_cost) {}
    edge() {}
};

void dijkstra(int s, vector<vector<edge>>& E, vector<double>& a)
{
    priority_queue<P, vector<P>, greater<P> > que;
    REP(i, a.size())
        a[i] = -1;
    a[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (a[v] >= 0 && a[v] < p.first)
            continue;
        for (int i = 0; i < E[v].size(); ++i)
        {
            edge e = E[v][i];
            if (a[e.to] < 0 || a[e.to] > a[v] + e.cost)
            {
                a[e.to] = a[v] + e.cost;
                que.push(P(a[e.to], e.to));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sx >> sy >> xx >> yy;

    int N;
    cin >> N;

    vector<Circle> v;
    v.push_back(Circle{sx, sy, 0});
    v.push_back(Circle{xx, yy, 0});
    REP(i, N) {
        int x, y, r;
        cin >> x >> y >> r;
        v.push_back(Circle{x, y, r});
    }

    vector<vector<edge>> E(v.size());

    REP(i, v.size()) {
        REP(j, v.size()) {
            auto vi = v[i];
            auto vj = v[j];
            double d = sqrt((vi.x - vj.x) * (vi.x - vj.x) + (vi.y - vj.y) * (vi.y - vj.y)) - vi.r - vj.r;
            if (d < 0) d = 0;
            E[i].push_back(edge(j, d));
            E[j].push_back(edge(i, d));
        }
    }

    vector<double> d(v.size());
    dijkstra(0, E, d);
    fcout << d[1] << endl;

    return 0;
}
