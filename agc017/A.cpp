
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

    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
        A[i] %= 2;
    }

    int dp[100][2];
    CLR(dp, 0);
    dp[0][0] = 1;
    REP(i, N) {
        if (A[i] == 1) {
            dp[i + 1][0] += dp[i][1] + dp[i][0];
            dp[i + 1][1] += dp[i][1] + dp[i][0];
        }
        else {
            dp[i + 1][0] += dp[i][0] * 2;
            dp[i + 1][1] += dp[i][1] * 2;
        }
    }
    cout << dp[N][P] << endl;
    return 0;
}
