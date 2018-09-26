
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

    int N, X;
    cin >> N >> X;
    vector<int> x(N + 1, 0);
    REP(i, N) cin >> x[i + 1];
    reverse(x.begin(), x.end());

    vector<int> sum(N + 1);
    REP(i, N) {
        sum[i + 1] = x[i] + sum[i];
    }

    int ans = INF;
    FOR(k, 1, N) {
        int res = (N + k) * X;
        FOR(i, 1, (N - 1) / k + 1) {
            int r = min(N, i * k);
            int l = k * (i - 1);
            if (i == 1) {
                res += 5 * (sum[r] - sum[l]);
            } else {
                res += (2 * i + 1) * (sum[r] - sum[l]);
            }
            if (res < 0) break;
        }
        if (res > 0) ans = min(res, ans);
    }

    cout << ans << endl;

    return 0;
}
