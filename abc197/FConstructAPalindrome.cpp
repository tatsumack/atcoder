#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> PP;

int dist[1003][1003];

class FConstructAPalindrome {
public:

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<vector<vector<int>>> G(N, vector<vector<int>>(26));
        REP(i, M) {
            int a, b;
            char c;
            cin >> a >> b >> c;
            a--, b--;
            G[a][c - 'a'].push_back(b);
            G[b][c - 'a'].push_back(a);
        }

        int INF = (1 << 30) - 1;

        queue<pair<int, int>> que;
        REP(i, N) REP(j, N) dist[i][j] = INF;

        dist[0][N - 1] = 0;
        que.push({0, N - 1});

        while (!que.empty()) {
            PP p = que.front();
            que.pop();
            REP(c, 26) {
                for (auto u : G[p.first][c]) {
                    for (auto v : G[p.second][c]) {
                        if (dist[u][v] > dist[p.first][p.second] + 2) {
                            dist[u][v] = dist[p.first][p.second] + 2;
                            que.push({u, v});
                        }
                    }
                }
            }
        }

        int res = INF;
        REP(i, N) {
            res = min(res, dist[i][i]);
        }
        REP(i, N) {
            REP(c, 26) {
                for (auto to : G[i][c]) {
                    res = min(res, dist[i][to] + 1);
                    res = min(res, dist[to][i] + 1);
                }
            }
        }
        if (res == INF) res = -1;
        cout << res << endl;
    }
};
