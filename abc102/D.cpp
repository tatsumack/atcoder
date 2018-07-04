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

int N;
int A[200005], sum[200005];

int solve(int l, int r, int mid) {
    int lsum, rsum;

    int mind = -1;
    FOR(i, mid, N) {
        lsum = l > 0 ? sum[i] - sum[l - 1] : sum[i];
        rsum = sum[r] - sum[i];
        if (mind == -1 || mind > abs(rsum - lsum)) {
            mid = i;
            mind = abs(rsum - lsum);
        } else {
            break;
        }
    }
    return mid;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) { cin >> A[i]; }

    sum[0] = A[0];
    FOR(i, 1, N - 1) { sum[i] = sum[i - 1] + A[i]; }

    int lmid = 0;
    int rmid = 0;
    int ans = INF;
    REP(mid, N) {
        lmid = solve(0, mid, lmid);
        rmid = solve(mid + 1, N - 1, max(rmid, mid + 1));
        int sum1 = sum[lmid];
        int sum2 = sum[mid] - sum[lmid];
        int sum3 = sum[rmid] - sum[mid];
        int sum4 = sum[N - 1] - sum[rmid];
        int minsum = min({sum1, sum2, sum3, sum4});
        int maxsum = max({sum1, sum2, sum3, sum4});

        ans = min(ans, abs(maxsum - minsum));
    }
    cout << ans << endl;

    return 0;
}
