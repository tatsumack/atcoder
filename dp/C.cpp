
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

    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    REP(i, N) cin >> a[i] >> b[i] >> c[i];

    int dp[100005][3];
    CLR(dp, 0);
    REP(i, N) {
        dp[i + 1][0] = max(dp[i][1] + a[i], dp[i][2] + a[i]);
        dp[i + 1][1] = max(dp[i][0] + b[i], dp[i][2] + b[i]);
        dp[i + 1][2] = max(dp[i][0] + c[i], dp[i][1] + c[i]);
    }
    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return 0;
}
