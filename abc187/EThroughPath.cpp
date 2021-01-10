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

class EThroughPath {
public:
    void dfs1(int v, int par, vector<vector<int>>& G, vector<int>& p) {
        p[v] = par;
        for (auto to : G[v]) {
            if (to == par) continue;
            dfs1(to, v, G, p);
        }
    }

    void dfs2(int v, int par, vector<vector<int>>& G, vector<int>& V, vector<int>& res) {
        res[v] += V[v];
        for (auto to : G[v]) {
            if (to == par) continue;
            res[to] += res[v];
            dfs2(to, v, G, V, res);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<vector<int>> G(N);
        vector<pair<int, int>> E(N);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
            E[i] = {a, b};
        }
        vector<int> v(N), p(N);
        dfs1(0, -1, G, p);

        int Q;
        cin >> Q;
        REP(i, Q) {
            int t, e, x;
            cin >> t >> e >> x;
            e--;
            if (p[E[e].first] == E[e].second) {
                if (t == 1) {
                    v[E[e].first] += x;
                } else {
                    v[0] += x;
                    v[E[e].first] -= x;
                }
            } else {
                if (t == 1) {
                    v[0] += x;
                    v[E[e].second] -= x;
                } else {
                    v[E[e].second] += x;
                }
            }
        }

        vector<int> res(N);
        dfs2(0, -1, G, v, res);
        REP(i, N) cout << res[i] << endl;
    }
};
