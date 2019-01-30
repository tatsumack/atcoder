
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

typedef pair<int, int> P;

vector<int> ES[105];

struct MaximumFlow {
    struct edge {
        int to;
        int cap;
        int rev;
    };

    int size;
    vector<vector<edge>> G;
    vector<bool> used;

    MaximumFlow(int n) {
        size = n;
        G.resize(n);
        used.resize(n);
    }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge){to, cap, static_cast<int>(G[to].size())});
        G[to].push_back((edge) {from, cap, static_cast<int>(G[from].size()) - 1});
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            edge& e = G[v][i];
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
        while (true) {
            used.clear();
            used.resize(size);
            int f = dfs(s, t, INF);

            if (f == 0) return flow;
            flow += f;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, G, E;
    cin >> N >> G >> E;
    vector<int> p(G);
    REP(i, G) cin >> p[i];

    MaximumFlow mf(N + 1);

    REP(i, E) {
        int a, b;
        cin >> a >> b;
        mf.add_edge(a, b, 1);
    }

    int g = N;
    REP(i, G) {
        mf.add_edge(p[i], g, 1);
    }

    int ans = mf.max_flow(0, g);
    cout << ans << endl;

    return 0;
}
