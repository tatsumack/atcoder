
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    REP(i, n) cin >> t[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    REP(j, n) {
        dp[j][1] = x;
    }
    REP(j, n) {
        FOR(k, 1, n - 1) {
            auto itr = lower_bound(t.begin(), t.end(), t[j] + x);
            int high = itr - t.begin();
            int low = high - 1;
            if (high > j) dp[high][k + 1] = max(dp[high][k + 1], dp[j][k] + min(t[high] - t[j], x));
            if (low > j) dp[low][k + 1] = max(dp[low][k + 1], dp[j][k] + min(t[low] - t[j], x));
        }
    }
    int ans = 0;
    FOR(k, 1, n) {
        REP(j, n) {
            ans = max(ans, dp[j][k]);
        }
        cout << ans << endl;
    }

    return 0;
}
