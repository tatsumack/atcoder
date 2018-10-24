
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

    int N;
    cin >> N;

    vector<char> C(2 * N);
    vector<int> A(2 * N);
    REP(i, 2 * N) cin >> C[i] >> A[i];

    vector<vector<int>> costb(2 * N, vector<int>(N + 2, 0));
    vector<vector<int>> costw(2 * N, vector<int>(N + 2, 0));
    vector<int> bpos(N + 1, -1);
    vector<int> wpos(N + 1, -1);

    REP(i, 2 * N) {
        if (C[i] == 'B') {
            costb[i][A[i]]++;
            bpos[A[i]] = i;
        }
        if (C[i] == 'W') {
            costw[i][A[i]]++;
            wpos[A[i]] = i;
        }
    }
    REP(i, 2 * N - 1) {
        FOR(j, 1, N) {
            costb[i + 1][j] += costb[i][j];
            costw[i + 1][j] += costw[i][j];
        }
    }
    REP(i, 2 * N) {
        REV(j, N - 1, 1) {
            costb[i][j] += costb[i][j + 1];
            costw[i][j] += costw[i][j + 1];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
    dp[0][0] = 0;
    REP(i, N + 1) {
        REP(j, N + 1) {
            if (i + 1 <= N) {
                int pos = bpos[i + 1];
                int cost = 0;
                if (pos > 0) {
                    cost += costb[pos - 1][i + 1] + costw[pos - 1][j + 1];
                }
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost);
            }
            if (j + 1 <= N) {
                int pos = wpos[j + 1];
                int cost = 0;
                if (pos > 0) {
                    cost += costb[pos - 1][i + 1] + costw[pos - 1][j + 1];
                }
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + cost);
            }
        }
    }

    cout << dp[N][N] << endl;

    return 0;
}
