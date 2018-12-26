
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

int N;
int a[1005], sum[1005];
int dp1[1005], dp2[1005];

bool check(int k) {
    REP(i, N + 10) dp1[i] = dp2[i] = -3000;

    dp1[N] = dp2[N] = 0;
    REV(i, N - 1, 0) {
        FOR(j, i + 1, N) {
            dp1[i] = max(dp1[i], (sum[j] - sum[i] >= k ? 1 : -1) - dp2[j]);
            dp2[i] = max(dp2[i], (sum[j] - sum[i] >= k ? -1 : 1) - dp1[j]);
        }
    }

    return dp1[0] >= 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    REP(i, N) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    int l = -INF;
    int r = INF;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}
