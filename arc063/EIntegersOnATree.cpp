#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class EIntegersOnATree {
public:
    vector<vector<int>> G;
    vector<P> range;
    vector<int> ans, p;

    bool ok;

    void dfs(int v, int par, int parity) {
        P res = range[v];
        if (res.first != -INF) {
            if (abs(res.first) % 2 != parity) {
                ok = false;
            }
        }
        for (auto to : G[v]) {
            if (to == par) continue;
            dfs(to, v, parity ^ 1);
            int l = max(res.first, range[to].first - 1);
            int r = min(res.second, range[to].second + 1);
            res = {l, r};
        }

        if (res.second < res.first) {
            ok = false;
        }
        range[v] = res;
    }

    void dfs2(int v, int val, int par) {
        ans[v] = val;
        for (auto to : G[v]) {
            if (to == par) continue;
            if (range[to].first <= val - 1) {
                dfs2(to, val - 1, v);
            } else if (range[to].second >= val + 1) {
                dfs2(to, val + 1, v);
            }
        }
    }


    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(N);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int K;
        cin >> K;
        vector<int> v(K);
        p.resize(K);
        REP(i, K) {
            cin >> v[i] >> p[i];
            v[i]--;
        }

        range.resize(N);
        REP(i, N) range[i] = {-INF, INF};
        REP(i, K) {
            range[v[i]] = {p[i], p[i]};
        }

        ok = true;
        dfs(v[0], -1, abs(p[0]) % 2);

        if (!ok) {
            cout << "No" << endl;
            return;
        }

        cout << "Yes" << endl;
        ans.resize(N);
        dfs2(v[0], p[0], -1);
        REP(i, N) {
            cout << ans[i] << endl;
        }
    }
};
