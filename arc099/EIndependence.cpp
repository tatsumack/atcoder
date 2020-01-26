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

class EIndependence {
public:
    vector<vector<int>> G;
    int N, M;

    vector<int> group;
    vector<P> nums;
    bool is_bipartite;

    void dfs(int v, int g, int p) {
        group[v] = g;
        if (g == 0) {
            nums.back().first++;
        } else {
            nums.back().second++;
        }
        REP(i, G[v].size()) {
            if (i == p) continue;
            if (G[v][i] == 0) continue;
            if (group[i] != -1 && group[i] != (g ^ 1)) {
                is_bipartite = false;
            }
            if (group[i] == -1) dfs(i, g ^ 1, v);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        G = vector<vector<int>>(N, vector<int>(N, 1));
        REP(i, N) G[i][i] = 0;
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a][b] = 0;
            G[b][a] = 0;
        }

        is_bipartite = true;
        group = vector<int>(N, -1);
        REP(i, N) {
            if (group[i] != -1) continue;
            nums.push_back({0, 0});
            dfs(i, 0, -1);
        }
        if (!is_bipartite) {
            cout << -1 << endl;
            return;
        }

        vector<vector<int>> dp(nums.size() + 1, vector<int>(N + 1));
        dp[0][0] = 1;
        REP(i, nums.size()) {
            REP(j, N) {
                if (dp[i][j] == 0) continue;

                auto kv = nums[i];
                if (j + kv.first <= N) dp[i + 1][j + kv.first] = 1;
                if (j + kv.second <= N) dp[i + 1][j + kv.second] = 1;
            }
        }

        int res = INF;
        REP(i, N + 1) {
            if (dp[nums.size()][i] == 0) continue;
            int a = i;
            int b = N - a;
            int tmp = a * (a - 1) / 2 + b * (b - 1) / 2;
            res = min(res, tmp);
        }
        cout << res << endl;
    }
};
