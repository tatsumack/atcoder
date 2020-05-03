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

class FLISOnTree {
public:
    vector<int> dp, A;
    int N;
    vector<vector<int>> G;
    vector<int> res;

    void dfs(int v, int p) {
        int val = A[v];
        int idx = lower_bound(dp.begin(), dp.end(), val) - dp.begin();
        int before = dp[idx];
        dp[idx] = val;
        res[v] = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
        for (auto to : G[v]) {
            if (to == p) continue;
            dfs(to, v);
        }
        dp[idx] = before;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        A.resize(N), res.resize(N);
        dp = vector<int>(N + 1, INF);
        REP(i, N) cin >> A[i];
        G.resize(N);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(0, -1);
        REP(i, N) cout << res[i] << endl;
    }
};
