
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
#include <queue>

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

int dp[200005][5]; // i番目までjの状態のときの最小操作回数

int count(int a, int j) {
    switch (j) {
        case 0:
        case 4:
            return a;
        case 1:
        case 3:
            if (a == 0) return 2;
            return a % 2;
        case 2:
            if (a == 0) return 1;
            return (a + 1) % 2;
        default:
            exit(1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L;
    cin >> L;
    vector<int> A(L);
    REP(i, L) cin >> A[i];

    REP(i, L + 1) REP(j, 5) dp[i][j] = INF;

    dp[0][0] = 0;
    REP(i, L) {
        int prev = dp[i][0];
        REP(j, 5) {
            prev = min(prev, dp[i][j]);
            dp[i + 1][j] = min(dp[i + 1][j], prev + count(A[i], j));
        }
    }

    int ans = INF;
    REP(j, 5) {
        ans = min(ans, dp[L][j]);
    }
    cout << ans << endl;

    return 0;
}
