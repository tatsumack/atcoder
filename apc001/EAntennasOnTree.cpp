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

class EAntennasOnTree {
public:
    vector<vector<int>> G;
    vector<int> in;

    int dfs(int v, int p) {
        int res = 0;
        int has = 0;
        for (auto to : G[v]) {
            if (to == p) continue;
            int tmp = dfs(to, v);
            if (tmp > 0) {
                has++;
            }
            res += tmp;
        }
        int req = p != -1 ? (int) G[v].size() - 2 : (int) G[v].size() - 1;
        return res + max(0LL, req - has);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(N);
        in.resize(N);
        REP(i, N - 1) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
            in[x]++, in[y]++;
        }

        bool ok = true;
        int root = -1;
        REP (i, N) {
            if (in[i] > 2) {
                ok = false;
                root = i;
            }
        }
        if (ok) {
            cout << 1 << endl;
            return;
        }

        int ans = dfs(root, -1);
        cout << ans << endl;
    }
};
