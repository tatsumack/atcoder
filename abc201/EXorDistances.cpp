#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

typedef atcoder::modint1000000007 mint;

using namespace std;

class EXorDistances {
public:
    vector<vector<pair<int, int>>> G;
    vector<int> dist;

    void dfs(int v, int p, int cur) {
        dist[v] = cur;
        for (auto kv : G[v]) {
            int to, cost;
            tie(to, cost) = kv;
            if (to == p) continue;
            dfs(to, v, cur ^ cost);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(N);
        dist.resize(N);
        REP(i, N - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }

        dfs(0, -1, 0);

        vector<vector<int>> cnt(65, vector<int>(2));
        REP(i, N) {
            int val = dist[i];
            REP(j, 61) {
                cnt[j][val >> j & 1]++;
            }
        }

        mint res = 0;
        REP(i, N) {
            int val = dist[i];
            REP(j, 61) {
                mint tmp;
                if (val >> j & 1) {
                    tmp = cnt[j][0];
                } else {
                    tmp = cnt[j][1];
                }
                tmp *= (1LL << j);
                res += tmp;
            }
        }
        res /= 2;
        cout << res.val() << endl;
    }
};
