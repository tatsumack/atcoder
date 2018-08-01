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
#define INF (LLONG_MAX - 1e5)

using namespace std;

string S;
int dp[105][105][105];  // i: 何番目の文字化 j: 最後に変えた文字までの移動回数
                        // k: (と)の個数差

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    REP(i, S.size() + 1) REP(j, S.size() + 1) REP(k, S.size() + 1) {
        dp[i][j][k] = INF;
    }
    dp[0][0][0] = 0;

    REP(i, S.size()) REP(j, S.size()) REP(k, S.size()) {
        if (dp[i][j][k] == INF) continue;
        char c = S[i];
        if (c == '(') {
            // 変更しないとき
            dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], dp[i][j][k]);
            // 変更するとき
            if (k > 0) {
                dp[i + 1][i][k - 1] = min(dp[i + 1][i][k - 1], dp[i][j][k] + 1);
            }
        } else {
            // 変更するとき
            dp[i + 1][i][k + 1] = min(dp[i + 1][i][k + 1], dp[i][j][k] + 1);
            // 変更しないとき
            if (k > 0) {
                dp[i + 1][j][k - 1] = min(dp[i + 1][j][k - 1], dp[i][j][k]);
            }
        }
    }

    int ans = INF;
    REP(i, S.size() + 1) { ans = min(ans, dp[S.size()][i][0] + i); }
    cout << ans << endl;

    return 0;
}
