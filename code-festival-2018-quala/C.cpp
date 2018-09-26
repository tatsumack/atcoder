
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

int dp[51][6000][2];

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

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    REP(i, N) cin >> a[i];

    vector<int> cnt(N, 0);
    REP(i, N) {
        while (a[i] > 0) {
            a[i] /= 2;
            cnt[i]++;
        }
    }

    dp[0][0][0] = 1;
    REP(i, N) {
        REP(j, 5000) {
            FOR(k, 0, cnt[i]) {
                if (k < cnt[i]) add(dp[i + 1][j+k][0], dp[i][j][0]);
                add(dp[i + 1][j+k][1], dp[i][j][1]);
            }
            add(dp[i + 1][j+cnt[i]][1], dp[i][j][0]);
        }
    }

    int ans = 0;
    REP(j, 5000) {
        if (j <= K) {
            add(ans, dp[N][j][1]);
        }
        if (j == K) add(ans, dp[N][j][0]);
    }

    cout << ans << endl;

    return 0;
}
