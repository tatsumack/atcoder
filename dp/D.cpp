
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

int dp[105][100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> w(N), v(N);
    REP(i, N) cin >> w[i] >> v[i];

    REP(i, N) {
        FOR(j, 0, W) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + w[i] <= W) {
                dp[i + 1][j + w[i]] = max(dp[i][j + w[i]], dp[i][j] + v[i]);
            }
        }
    }

    int ans = 0;
    FOR(j, 0, W) {
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
    return 0;
}
