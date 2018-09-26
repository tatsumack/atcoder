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

int dp[100005][31];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> B(N);
    REP(i, N) cin >> A[i] >> B[i];

    REP(i, N) {
        if ((K | A[i]) == K) {
            dp[i + 1][0] = dp[i][0] + B[i];
        }
        else {
            dp[i + 1][0] = dp[i][0];
        }
        FOR(j, 1, 30) {
            if ((K & (1 << j)) == 0) continue;
            int t = K;
            t ^= 1 << j;
            t |= (1 << j) - 1;
            if ((t | A[i]) == t) {
                dp[i+1][j] = dp[i][j] + B[i];
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    int ans = 0;
    REP(j, 31) {
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;

    return 0;
}
