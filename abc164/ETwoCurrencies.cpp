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

class ETwoCurrencies {
public:
    vector<int> it, ic;
    vector<vector<tuple<int, int, int>>> G;

    void dfs(int v, int p) {

    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, S;
        cin >> N >> M >> S;
        G.resize(N);
        int sum = 0;
        REP(i, M) {
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            u--, v--;
            G[u].emplace_back(v, a, b);
            G[v].emplace_back(u, a, b);
            sum += a;
        }
        vector<int> C(N), D(N);
        REP(i, N) {
            cin >> C[i] >> D[i];
        }

        if (S > sum) {
            S = sum;
        }
        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<>> pq;
        vector<vector<int>> dist(N, vector<int>(sum + 1, INF));
        dist[0][S] = 0;
        pq.push({0, {0, S}});
        while (!pq.empty()) {
            auto[cost, vv] = pq.top();
            auto[from, money] = vv;
            pq.pop();
            if (dist[from][money] < cost) continue;
            for (auto v : G[from]) {
                auto[to, a, b] = v;
                if (money - a < 0) continue;
                if (cost + b < dist[to][money - a]) {
                    dist[to][money - a] = cost + b;
                    pq.push({dist[to][money - a], {to, money - a}});
                }
            }
            int newmoney = money + C[from];
            if (newmoney > sum) newmoney = sum;
            if (cost + D[from] < dist[from][newmoney]) {
                dist[from][newmoney] = cost + D[from];
                pq.push({dist[from][newmoney], {from, newmoney}});
            }
        }
        FOR(i, 1, N - 1) {
            int res = INF;
            FOR(j, 0, sum) {
                res = min(res, dist[i][j]);
            }
            cout << res << endl;
        }
    }
};
