
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

int dp[3005][3005][2];
int a[3005];

int dfs(int l, int r, int k) {
    if (dp[l][r][k] != INF) return dp[l][r][k];

    if (l == r) {
        return k == 0 ? a[l] : -a[l];
    }

    int res;
    if (k == 0) {
        res = max(a[l] + dfs(l + 1, r, 1), a[r] + dfs(l, r - 1, 1));
    } else {
        res = min(dfs(l + 1, r, 0) - a[l], dfs(l, r - 1, 0) - a[r]);
    }

    return dp[l][r][k] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    REP(i, N) cin >> a[i];

    REP(l, N) REP(r, N) REP(k, 2) dp[l][r][k] = INF;

    cout << dfs(0, N - 1, 0) << endl;

    return 0;
}
