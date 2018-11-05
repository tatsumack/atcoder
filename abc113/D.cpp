
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

    int H, W, K;
    cin >> H >> W >> K;

    int dp[105][10];
    CLR(dp, 0);

    dp[0][0] = 1;
    REP(i, H) {
        REP(j, W) {
            REP(k, 1 << W - 1) {
                bool ok = true;
                REP(kk, W - 2) {
                    if (((k >> kk) & 1) == 0) continue;
                    if (((k >> (kk + 1)) & 1) == 0) continue;
                    ok = false;
                    break;
                }
                if (!ok) continue;

                int jj = j;
                if (j > 0 && ((k >> (j - 1) & 1) == 1)) jj--;
                if (((k >> j) & 1) == 1) jj++;
                add(dp[i + 1][jj], dp[i][j]);
            }
        }
    }
    cout << dp[H][K - 1] << endl;

    return 0;
}
