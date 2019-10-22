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

class CRemovingCoins {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;

    // 木の直径
    P dfs(int v, int par) {
        P res = {0, v};

        REP(i, G[v].size()) {
            int to = G[v][i];
            if (to == par) continue;
            auto tmp = dfs(to, v);
            tmp.first++;
            res = max(tmp, res);
        }

        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G = vector<vector<int>>(N);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        auto u = dfs(0, -1);
        auto v = dfs(u.second, -1);

        vector<int> dp(N+1);
        dp[1] = 1;
        dp[2] = 0;
        FOR(i, 3, N) {
            if (dp[i-1] == 0 || dp[i-2] == 0) {
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }
        }

        int len = v.first + 1;
        if (dp[len] == 1) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        };
    }
};
