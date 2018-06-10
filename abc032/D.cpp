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

typedef pair<int, int> P;

int N, W, v[500], w[500], dp[300005];

int napsack1() {
    int n2 = N / 2;

    vector<P> vp;
    REP(i, 1 << n2) {
        int sw = 0;
        int sv = 0;
        REP(j, n2) {
            if (i >> j & 1) {
                sw += w[j];
                sv += v[j];
            }
        }
        vp.push_back({sw, sv});
    }

    sort(vp.begin(), vp.end());

    int m = 1;
    FOR(i, 1, vp.size() - 1) {
        if (vp[m - 1].second < vp[i].second) {
            vp[m] = vp[i];
            m++;
        }
    }

    int n1 = N - n2;
    int ans = 0;
    REP(i, 1 << n1) {
        int sw = 0;
        int sv = 0;
        REP(j, n1) {
            if (i >> j & 1) {
                sw += w[j + n2];
                sv += v[j + n2];
            }
        }
        if (sw > W) continue;
        int t = (lower_bound(vp.begin(), vp.begin() + m, P{W - sw, INF}) - 1)
                    ->second;
        ans = max(ans, sv + t);
    }
    return ans;
}

int napsack2() {
    REV(j, W, 0) { dp[j] = 0; }
    REP(i, N) {
        REV(j, W, 0) {
            if (j - w[i] >= 0) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    return dp[W];
}

int napsack3() {
    int sumv = N * 1005;
    REV(j, sumv, 0) { dp[j] = INF; }
    dp[0] = 0;

    REP(i, N) {
        REV(j, sumv, 0) {
            if (j - v[i] >= 0) {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    REV(j, sumv, 0) {
        if (dp[j] <= W) {
            return j;
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> W;

    int maxw = 0;
    REP(i, N) {
        cin >> v[i] >> w[i];
        maxw = max(maxw, w[i]);
    }

    int ans = 0;
    if (N <= 30) {
        ans = napsack1();
    } else if (maxw <= 1000) {
        ans = napsack2();
    } else {
        ans = napsack3();
    }
    cout << ans << endl;
    return 0;
}
