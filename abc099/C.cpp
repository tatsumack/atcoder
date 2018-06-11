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

int N, dp[100000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    dp[0] = 0;
    FOR(n, 1, N) {
        dp[n] = dp[n - 1] + 1;

        int c6 = 1;
        while (c6 * 6 <= n) {
            c6 *= 6;
            dp[n] = min(dp[n], dp[n - c6] + 1);
        }

        int c9 = 1;
        while (c9 * 9 <= n) {
            c9 *= 9;
            dp[n] = min(dp[n], dp[n - c9] + 1);
        }
    }
    cout << dp[N] << endl;
    return 0;
}
