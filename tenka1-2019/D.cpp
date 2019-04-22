
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

int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int MAX_A = 90600;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);

    int s = 0;
    REP(i, N) {
        cin >> a[i];
        s += a[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(MAX_A, 0));
    dp[0][0] = 1;
    REP(i, N) {
        int n = a[i];
        REP(j, s + 1) {
            add(dp[i + 1][j], (dp[i][j] * 2) % mod);
            if (j + n < MAX_A) add(dp[i + 1][j + n], dp[i][j]);
        }
    }

    vector<vector<int>> dp2(N + 1, vector<int>(MAX_A, 0));
    dp2[0][0] = 1;
    REP(i, N) {
        int n = a[i];
        REP(j, s + 1) {
            add(dp2[i + 1][j], dp2[i][j]);
            if (j + n < MAX_A) add(dp2[i + 1][j + n], dp2[i][j]);
        }
    }

    int res = 1;
    REP(i, N) {
        res *= 3;
        res %= mod;
    }

    int tmp = 0;
    FOR(i, (s + 1) / 2, s) {
        add(tmp, (dp[N][i] * 3) % mod);
    }
    res -= tmp;
    if (res < 0) res += mod;

    if (s % 2 == 0)
        add(res, (dp2[N][s / 2] * 3) % mod);

    cout << res << endl;

    return 0;
}
