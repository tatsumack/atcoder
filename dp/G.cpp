
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

vector<int> G[200005];
int memo[200005];

int dfs(int v) {
    if (memo[v] != -1) return memo[v];

    int res = 0;
    REP(i, G[v].size()) {
        res = max(res, dfs(G[v][i]) + 1);
    }

    return memo[v] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }

    REP(i, N) memo[i] = -1;

    int ans = 0;
    REP(i, N) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;

    return 0;
}
