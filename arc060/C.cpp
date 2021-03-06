
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
int dp[51][51][3000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    REP(i, N) cin >> x[i];

    CLR(dp, 0);

    dp[0][0][0] = 1;
    REP(i, N) {
        REP(j, N) {
            REP(k, 3000) {
                dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
                dp[i + 1][j][k] += dp[i][j][k];
            }
        }
    }

    int ans = 0;
    FOR(j, 1, N) {
        ans += dp[N][j][j * A];
    }
    cout << ans << endl;

    return 0;
}
