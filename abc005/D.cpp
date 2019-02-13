
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

int D[55][55];

int dp[3000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N;
    REP(i, N) REP(j, N) cin >> D[i][j];

    cin >> Q;
    vector<int> P(Q);
    REP(i, Q) cin >> P[i];

    REP(i, N) {
        REP(j, N - 1) {
            D[i][j + 1] += D[i][j];
        }
    }
    REP(j, N) {
        REP(i, N - 1) {
            D[i + 1][j] += D[i][j];
        }
    }

    FOR(low, 0, N - 1) {
        FOR(high, low, N - 1) {
            FOR(left, 0, N - 1) {
                FOR(right, left, N - 1) {
                    int point = D[high][right];
                    if (left > 0) point -= D[high][left - 1];
                    if (low > 0) point -= D[low - 1][right];
                    if (left > 0 && low > 0) point += D[low - 1][left - 1];

                    int area = (high - low + 1) * (right - left + 1);
                    dp[area] = max(dp[area], point);
                }
            }
        }
    }

    REP(i, N * N) {
        dp[i+1] = max(dp[i+1], dp[i]);
    }

    REP(i, Q) {
        cout << dp[P[i]] << endl;
    }

    return 0;
}
