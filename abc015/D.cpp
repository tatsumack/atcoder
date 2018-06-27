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
#define INF (3e15)

using namespace std;

int N, K, W, A[100], B[100];
int dp[55][55][10005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> N >> K;
    REPS(i, N) cin >> A[i] >> B[i];

    FOR(i, 1, N) FOR(k, 1, K) FOR(w, 0, W) {
        if (w - A[i] < 0) {
            dp[i][k][w] = dp[i - 1][k][w];
            continue;
        }
        dp[i][k][w] = max(dp[i - 1][k][w], dp[i - 1][k - 1][w - A[i]] + B[i]);
    }

    cout << dp[N][K][W] << endl;

    return 0;
}
