
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

int visited[55][55][55];
int ok[55][55][55];
int dp[55][55][55][2];
string s;

bool f(int l, int r, int k) {
    if (visited[l][r][k]) return ok[l][r][k];
    if ((r - l) % 2 != 0) return false;
    visited[l][r][k] = true;

    if (l == r) {
        if (k == 0) {
            if (isdigit(s[l])) {
                dp[l][r][0][0] = s[l] - '0';
                dp[l][r][0][1] = s[l] - '0';
                return ok[l][r][0] = true;
            }
            return false;
        } else {
            dp[l][r][k][0] = 1;
            dp[l][r][k][1] = 9;
            return ok[l][r][k] = true;
        }
    }

    int res0 = INF;
    int res1 = -INF;

    int left = k;
    if (s[r] != '+') left--;
    if (left >= 0) {
        FOR(m, l, r - 2) FOR (kk, 0, left) {
                if (!f(l, m, kk) || !f(m + 1, r - 1, left - kk)) continue;
                ok[l][r][k] = true;
                res0 = min(res0, dp[l][m][kk][0] + dp[m + 1][r - 1][left - kk][0]);

                int test1 = dp[l][m][kk][1];
                int test2 = dp[m + 1][r - 1][left - kk][1];
                res1 = max(res1, dp[l][m][kk][1] + dp[m + 1][r - 1][left - kk][1]);
            }
    }

    left = k;
    if (s[r] != '-') left--;
    if (left >= 0) {
        FOR(m, l, r - 2) FOR (kk, 0, left) {
                if (!f(l, m, kk) || !f(m + 1, r - 1, left - kk)) continue;
                ok[l][r][k] = true;
                res0 = min(res0, dp[l][m][kk][0] - dp[m + 1][r - 1][left - kk][1]);
                res1 = max(res1, dp[l][m][kk][1] - dp[m + 1][r - 1][left - kk][0]);
            }
    }

    dp[l][r][k][0] = res0;
    dp[l][r][k][1] = res1;
    return ok[l][r][k];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> K;
    cin >> s;

    int ans = -INF;
    FOR(k, 0, K) {
        if (!f(0, s.size() - 1, k)) continue;
        ans = max(ans, dp[0][s.size()-1][k][1]);
    }

    if (ans == -INF) {
        cout << "NG" << endl;
        return 0;
    }

    cout << "OK" << endl;
    cout << ans << endl;

    return 0;
}
