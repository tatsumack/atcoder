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

struct edge {
    int to, cost;

    edge(int to, int cost) : to(to), cost(cost) {}
};
class C {
public:
    vector<vector<edge>> G;
    map<int, int> cnt;
    int N, X, res;
    vector<int> dp;

    void dfs(int v, int p) {
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            dp[e.to] = dp[v] ^ e.cost;
            res += cnt[dp[e.to] ^ X];
            cnt[dp[e.to]]++;
            dfs(e.to, v);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> X;
        G.resize(N), dp.resize(N);
        REP(i, N - 1) {
            int x, y, c;
            cin >> x >> y >> c;
            x--, y--;
            G[x].emplace_back(y, c);
            G[y].emplace_back(x, c);
        }

        res = 0;
        cnt[0]++;
        dfs(0, -1);
        cout << res << endl;
    }
};
