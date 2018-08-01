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

int dp[100005][10];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    FOR(i, 1, S.size()) { dp[i][0] = i; }
    REP(i, 5) { dp[0][i] = i; }

    string test = "yahoo";
    FOR(i, 1, S.size()) {
        FOR(j, 1, 10) {
            int cost = S[i - 1] == test[(j - 1) % 5] ? 0 : 1;
            dp[i][j % 5] = min({dp[i - 1][j % 5] + 1, dp[i][(j - 1) % 5] + 1,
                                dp[i - 1][(j - 1) % 5] + cost});
        }
    }
    cout << dp[S.size()][0] << endl;
    return 0;
}
