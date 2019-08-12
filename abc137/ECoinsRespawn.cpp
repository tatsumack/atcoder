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

class ECoinsRespawn {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    struct edge {
        int from, to, cost;

        edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}

        edge() {}
    };

    int N, M, P;
    vector<edge> edges;
    vector<int> d;
    vector<bool> neg;
    vector<vector<int>> to, rto;

    vector<bool> visit, rvisit;

    void dfs(int v) {
        if (visit[v]) return;
        visit[v] = true;
        for (int n : to[v]) {
            dfs(n);
        }
    }

    void rdfs(int v) {
        if (rvisit[v]) return;
        rvisit[v] = true;
        for (int n : rto[v]) {
            rdfs(n);
        }
    }

    void calc(int s) {
        REP(i, N) d[i] = INF;
        d[s] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < edges.size(); j++) {
                auto e = edges[j];
                if (!visit[e.from] || !rvisit[e.from]) continue;
                if (!visit[e.to] || !rvisit[e.to]) continue;
                if (d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    if (i == N - 1) {
                        d[N - 1] = INF;
                        break;
                    }
                }
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> P;
        edges.clear();
        d.resize(N);
        neg.resize(N);
        to.resize(N), rto.resize(N), visit.resize(N), rvisit.resize(N);
        REP(i, M) {
            int a, b, c;
            cin >> a >> b >> c;
            edge e;
            a--;
            b--;
            c -= P;
            edges.push_back(edge(a, b, -c));
            to[a].push_back(b);
            rto[b].push_back(a);
        }

        dfs(0);
        rdfs(N - 1);

        calc(0);

        if (d[N - 1] >= INF) {
            cout << -1 << endl;
        } else {
            cout << max(-d[N - 1], 0LL) << endl;
        }
    }
};
