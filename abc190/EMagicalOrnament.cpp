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

class EMagicalOrnament {
public:
    int N, M, K;
    vector<vector<int>> G, dist;
    vector<int> C;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        G.resize(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cin >> K;
        C.resize(K);
        map<int, int> m;
        REP(i, K) {
            cin >> C[i];
            C[i]--;
            m[C[i]] = i;
        }

        dist = vector<vector<int>>(K, vector<int>(K, INF));
        for (auto c : C) {
            queue<pair<int, int>> q;
            q.push({c, 0});
            vector<bool> visited(N);
            visited[c] = true;
            while (!q.empty()) {
                int v, cost;
                tie(v, cost) = q.front();
                q.pop();
                if (m.count(c) && m.count(v)) {
                    dist[m[c]][m[v]] = min(dist[m[c]][m[v]], cost);
                }
                for (auto to : G[v]) {
                    if (visited[to]) continue;
                    q.push({to, cost + 1});
                    visited[to] = true;
                }
            }
        }
        bool ok = true;
        REP(i, K) {
            REP(j, K) {
                if (dist[i][j] == INF) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }
        vector<vector<int>> dp(1LL << K, vector<int>(K, INF));
        REP(i, K) dp[1LL << i][i] = 1;
        REP(s, 1LL << K) {
            REP(i, K) {
                if ((s >> i & 1) == 0) continue;
                REP(j, K) {
                    dp[s | (1LL << j)][j] = min(dp[s | (1LL << j)][j], dp[s][i] + dist[i][j]);
                }
            }
        }
        int res = INF;
        REP(j, K) {
            res = min(res, dp[(1LL << K) - 1][j]);
        }
        cout << res << endl;
    }
};
