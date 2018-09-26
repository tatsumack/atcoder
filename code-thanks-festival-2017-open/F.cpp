
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

void add(int& a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int dp[2][100005];
    CLR(dp, 0);

    dp[0][0] = 1;
    int cur = 0;
    int limit = 0;
    REP(i, n) {
        int next = cur ^1;
        FOR(j, 0, limit) {
            dp[next][j] = 0;
        }
        FOR(j, 0, limit) {
            add(dp[next][j], dp[cur][j]);
            add(dp[next][j ^ a[i]], dp[cur][j]);
        }
        limit |= a[i];
        cur ^= 1;
    }

    cout << dp[cur][k] << endl;


    return 0;
}
