
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;

vector<int> G[100005];

int dp[100005][2]; // 0: white, 1: black

int mod = 1e9 + 7;

int dfs(int n, int c, int p) {
    if (dp[n][c] > 0) return dp[n][c];

    int res = 1;

    REP(i, G[n].size()) {
        if (G[n][i] == p) continue;

        int child = G[n][i];
        if (c == 0) {
            // white
            res *= (dfs(child, 0, n) + dfs(child, 1, n)) % mod;
            res %= mod;
        } else {
            // black
            res *= dfs(child, 0, n);
            res %= mod;
        }
    }

    return dp[n][c] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    REP(i, N - 1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);

        dp[i][0] = dp[i][1] = -1;
    }

    int ans = dfs(0, 0, -1) + dfs(0, 1, -1);
    cout << ans % mod << endl;

    return 0;
}
