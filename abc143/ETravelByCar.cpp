#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> PP;

class ETravelByCar {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int n, m, l;

    vector<vector<P>> d;
    vector<vector<P>> G;

    void dijkstra(int s) {
        priority_queue<PP, vector<PP>, greater<PP>> que;
        REP(i, n) d[s][i] = {INF, INF};
        d[s][s] = {0,0};
        que.push({{0, 0}, s});

        while (!que.empty()) {
            auto p = que.top();
            que.pop();
            int v = p.second;
            int count = p.first.first;
            int used = p.first.second;

            if (d[s][v] < p.first) continue;
            for (int i = 0; i < G[v].size(); ++i) {
                auto e = G[v][i];
                if (e.second > l) continue;

                int ncount = count;
                int nused = used + e.second;
                if (nused > l) {
                    ncount++;
                    nused = e.second;
                }
                P np = {ncount, nused};
                if (np < d[s][e.first]) {
                    d[s][e.first] = np;
                    que.push({d[s][e.first], e.first});
                }
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> n >> m >> l;

        d = vector<vector<P>>(n, vector<P>(n, {INF, INF}));
        G = vector<vector<P>>(n);
        REP(i, m) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }

        REP(i, n) {
            dijkstra(i);
        }

        int q;
        cin >> q;
        while (q--) {
            int s, t;
            cin >> s >> t;
            s--, t--;
            if (d[s][t].first == INF) {
                cout << -1 << endl;
            } else {
                cout << d[s][t].first << endl;
            }
        }
    }
};
