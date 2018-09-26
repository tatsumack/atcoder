
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

int binpow(int x, int p) {
    if (p == 0) return 1;

    if (p % 2 == 0)
        return binpow((x * x) % mod, p / 2);
    else
        return (x * binpow(x, p - 1)) % mod;
}

// mod
void add(int& a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int D, F, T, N;
    cin >> D >> F >> T >> N;

    vector<int> x(N + 1);
    x[0] = 0;
    REP(i, N) cin >> x[i + 1];

    vector<int> cnt(N + 1);

    int r = 0;
    REP(l, N + 1) {
        while (r + 1 <= N && x[r + 1] - x[l] <= F - T) {
            r++;
        }
        cnt[l] = binpow(2, r - l);
        if (l == r) r++;
    }

    vector<int> dp(N + 2);
    vector<int> sum(N + 2);

    dp[0] = 1;
    sum[1] = (dp[0] * cnt[0]) % mod;
    FOR(i, 1, N) {
        int l = lower_bound(x.begin(), x.end(), x[i] - F) - x.begin();
        int rr = lower_bound(x.begin(), x.end(), x[i] - (F - T)) - x.begin();
        dp[i] = (sum[rr] - sum[l] + mod) % mod;
        sum[i+1] = (dp[i] * cnt[i] % mod + sum[i]) % mod;
    }

    int ans = 0;
    REP(i, N + 1) {
        if (D - x[i] <= F) add(ans, (dp[i] * cnt[i]) % mod);
    }

    cout << ans << endl;
    return 0;
}
