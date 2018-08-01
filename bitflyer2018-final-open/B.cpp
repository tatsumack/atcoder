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
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N, Q, X[100005], C[100005], D[100005], sum[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    REP(i, N) cin >> X[i];
    REP(i, Q) cin >> C[i] >> D[i];
    sort(X, X + N);

    REP(i, N) sum[i + 1] = sum[i] + X[i];

    REP(i, Q) {
        int c = C[i];
        int d = D[i];

        int l = lower_bound(X, X + N, c - d) - X;
        int m = lower_bound(X, X + N, c) - X;
        int r = lower_bound(X, X + N, c + d) - X;

        int ans = 0;
        ans += l * d;
        ans += c * (m - l) - (sum[m] - sum[l]);
        ans += (sum[r] - sum[m]) - c * (r - m);
        ans += (N - r) * d;

        cout << ans << endl;
    }
    return 0;
}
