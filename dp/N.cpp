
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

int dp[500][500];

vector<int> a(500);
vector<int> sum(500);

int dfs(int l, int r) {
    if (dp[l][r] >= 0) return dp[l][r];
    if (r - l == 1) return dp[l][r] = 0;

    int res = INF;
    FOR(k, l + 1, r - 1) {
        int tmp = dfs(l, k) + dfs(k, r);
        res = min(res, tmp);
    }

    return dp[l][r] = res + sum[r] - sum[l];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    CLR(dp, -1);

    int N;
    cin >> N;
    REP(i, N) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    cout << dfs(0, N) << endl;
    return 0;
}
