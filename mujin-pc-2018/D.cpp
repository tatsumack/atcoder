
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

int rev(int x) {
    int res = 0;
    while (x != 0) {
        res *= 10;
        res += x % 10;
        x /= 10;
    }

    return res;
}

int dp[1000][1000];

bool solve(int a, int b, int cnt) {
    if (cnt == 1000) return true;
    if (a == 0 || b == 0) return false;
    if (a > b) swap(a, b);
    if (dp[a][b] == 2) {
        return false;
    }
    if (dp[a][b] == 1) return true;

    int ra = rev(a);
    return ra < b ? solve(ra, b - ra, cnt + 1) : solve(ra - b, b, cnt + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int ans = 0;
    REPS(i, N) {
        REPS(j, M) {
            if (solve(i, j, 0)) {
                dp[i][j] = 1;
                dp[j][i] = 1;
                ans++;
            } else {
                dp[i][j] = 2;
                dp[j][i] = 2;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
