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

class EUniqueColor {
public:
    int N;
    vector<int> C;
    vector<vector<int>> G;
    map<int, int> cnt;
    vector<int> res;

    void dfs(int v, int p) {
        if (cnt[C[v]] == 0) {
            res.push_back(v);
        }
        for (auto to : G[v]) {
            if (to == p) continue;
            cnt[C[v]]++;
            dfs(to, v);
            cnt[C[v]]--;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        C.resize(N);
        G.resize(N);
        REP(i, N) cin >> C[i];
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        dfs(0, -1);
        sort(res.begin(), res.end());
        REP(i, res.size()) cout << res[i] + 1 << endl;
    }
};
