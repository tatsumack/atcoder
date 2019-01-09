
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

int MAXV = 100000;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> w(N), v(N);
    REP(i, N) cin >> w[i] >> v[i];

    FOR(i, 0, N) FOR(j, 0, MAXV) dp[i][j] = INF;

    dp[0][0] = 0;
    REP(i, N) {
        FOR(j, 0, MAXV) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j + v[i] <= MAXV) {
                dp[i + 1][j + v[i]] = min(dp[i][j + v[i]], dp[i][j] + w[i]);
            }
        }
    }

    int ans = 0;
    FOR(j, 0, MAXV) {
        if (dp[N][j] <= W)
        {
            ans = j;
        }
    }
    cout << ans << endl;
    return 0;
}
