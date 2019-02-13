
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

int OFFSET = 1000;
int dp[2010][1000];

int R, G, B;

int count(int pos, int remain) {
    if (remain > G + B) {
        return abs(400 - pos);
    } else if (remain > B) {
        return abs(500 - pos);
    } else {
        return abs(600 - pos);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> G >> B;

    int sum = R + G + B;
    FOR(i, 0, 1000) REP(j, sum) {
            dp[i][j] = INF;
        }

    FOR(i, 0, 1000) dp[i][sum] = 0;

    FOR(i, 0, 1000) {
        REP(j, sum + 1) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j > 0) {
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + count(i, j));
            }
        }
    }

    int ans = INF;
    FOR(i, 0, 1000) ans = min(ans, dp[i][0]);
    cout << ans << endl;

    return 0;
}
