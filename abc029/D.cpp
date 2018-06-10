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

string N;
int dp[100][2][15];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp[0][1][0] = 1;
    REP(i, N.size()) {
        REP(j, 2) REP(k, 15) {
            if (dp[i][j][k] == 0) continue;
            int t = j ? N[i] - '0' : 9;
            FOR(m, 0, t) {
                if (m == 1) {
                    dp[i + 1][j && m == t][k + 1] += dp[i][j][k];
                } else {
                    dp[i + 1][j && m == t][k] += dp[i][j][k];
                }
            }
        }
    }
    int ans = 0;
    REP(j, 2) REP(k, 15) {
        if (dp[N.size()][j][k] == -1) continue;
        ans += dp[N.size()][j][k] * k;
    }
    cout << ans << endl;
    return 0;
}
