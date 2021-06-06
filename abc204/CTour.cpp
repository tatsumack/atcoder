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

class CTour {
public:
    int N, M;
    vector<vector<int>> G;

    int res;
    vector<bool> visited;

    void dfs(int v, int p) {
        res++;
        visited[v] = true;
        for (auto to : G[v]) {
            if (to == p) continue;
            if (visited[to]) continue;
            visited[to] = true;
            dfs(to, v);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        G.resize(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
        }

        res = 0;
        REP(i, N) {
            visited = vector<bool>(N);
            dfs(i, -1);
        }
        cout << res << endl;
    }
};
