
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

int dp[100005][10];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string T;
    cin >> T;

    int ans = 0;
    REP(i, T.size()) {
        if (i == 0) continue;
        char c = T[i];
        char prev = T[i - 1];
        if (c == '?') {
            if (prev == '2' || prev == '?') {
                dp[i][5] = dp[i - 1][2] + 2;
            }
            dp[i][2] = dp[i - 1][5];
        }
        if (c == '2') {
            dp[i][2] = dp[i - 1][5];
        }
        if (c == '5') {
            if (prev == '2' || prev == '?') {
                dp[i][5] = dp[i - 1][2] + 2;
            }
        }
        ans = max(ans, dp[i][5]);
    }
    cout << ans << endl;
    return 0;
}
