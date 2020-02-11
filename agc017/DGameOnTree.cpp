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

class DGameOnTree {
public:
    vector<vector<int>> G;

    int dfs(int v, int p) {
        int res = 0;
        for (auto to : G[v]) {
            if (to == p) continue;
            int tmp = dfs(to, v);
            res ^= (tmp + 1);
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(N);
        REP(i, N - 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans = dfs(0, -1);
        cout << (ans > 0 ? "Alice" : "Bob") << endl;
    }
};
