
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

int mod = 1e9 + 7;
int dp[105][300005];

void add(int& a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    dp[0][0] = 1;
    REP(i, N) {
        vector<int> sum(K + 2, 0);
        FOR(k, 0, K) {
            sum[k + 1] = (sum[k] + dp[i][k]) % mod;
        }
        FOR(k, 0, K) {
            int to = k + 1;
            int from = max(k - a[i], 0LL);
            int diff = sum[to] - sum[from];
            if (diff < 0) diff += mod;
            add(dp[i + 1][k], diff);
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}
