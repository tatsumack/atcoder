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
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, A[50], B[50], C[50], MA, MB, dp[50][500][500];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> MA >> MB;
    REP(i, N) { cin >> A[i] >> B[i] >> C[i]; }

    REP(i, N + 1) REP(j, 500) REP(k, 500) { dp[i][j][k] = INF; }

    dp[0][0][0] = 0;
    REPS(i, N) REP(j, 500) REP(k, 500) {
        if (j - A[i - 1] < 0 || k - B[i - 1] < 0) {
            dp[i][j][k] = dp[i - 1][j][k];
            continue;
        }
        dp[i][j][k] = min(dp[i - 1][j][k],
                          dp[i - 1][j - A[i - 1]][k - B[i - 1]] + C[i - 1]);
    }

    int ans = INF;
    int c = 1;
    while (MA * c <= N * 10 && MB * c <= N * 10) {
        ans = min(ans, dp[N][MA * c][MB * c]);
        c++;
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
