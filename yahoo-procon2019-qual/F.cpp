
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

int dp[4005][4005];
int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int N = s.size();

    vector<int> sum(N + 1, 0);
    REP(i, N) {
        char c = s[i];
        int r = 0;
        switch (c) {
            case '0':
                r += 2;
                break;
            case '1':
                r += 1;
                break;
        }
        sum[i + 1] = sum[i] + r;
    }

    dp[0][0] = 1;
    REP(i, 2 * N) {
        REP(r, sum[i] + 1) {
            if (r > i) break;

            int t = i + 1 > N ? N : i + 1;

            // 赤を足す
            if (sum[t] >= r + 1) {
                dp[i + 1][r + 1] += dp[i][r];
                dp[i + 1][r + 1] %= mod;
            }
            // 青を足す
            if ((i + 1) * 2 - sum[t] >= i + 1 - r) {
                dp[i + 1][r] += dp[i][r];
                dp[i + 1][r] %= mod;
            }
        }
    }

    cout << dp[2 * N][sum[N]] << endl;
    return 0;
}
