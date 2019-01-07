
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

    int L, N;
    cin >> L >> N;

    vector<int> X(N + 1);
    X[0] = 0;
    REP(i, N) {
        cin >> X[i + 1];
    }

    int dp[2500][2500][2];
    CLR(dp, 0);
    REP(i, N + 1) {
        REV(j, N, i + 1) {
            if (i < N) {
                dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + X[i + 1] - X[i]);
            }
            if (j - 1 > i + 1) {
                dp[i + 1][j - 1][1] = max(dp[i][j - 1][1], dp[i + 1][j][0] + X[i] + L - X[j - 1]);
            }
            if (i < N) {
                dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][1] + L - X[j] + );
            }
            if (j - 1 > i) {
                dp[i][j - 1][1] = max(dp[i][j - 1][1], dp[i][j][1] + X[j] - X[j - 1]);
            }
        }
    }
}

return 0;
}
