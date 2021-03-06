
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

    string A;
    cin >> A;

    int n = A.size();

    vector<int> next(26, 0);
    vector<vector<int>> np(n + 2, vector<int>(26, 0));
    REP(i, 26) np[n][i] = next[i] = n + 1;

    vector<int> dp(n + 2);
    REV(i, n, 0) {
        int tmp = INF;
        REP(j, 26) {
            np[i][j] = next[j];
            int pos = next[j];
            int v = dp[pos];
            if (v < tmp) {
                tmp = v;
            }
        }
        dp[i] = tmp + 1;
        if (i > 0) next[A[i - 1] - 'a'] = i;
    }

    int cur = 0;
    string ans;
    while (cur < n + 1) {
        REP(j, 26) {
            int pos = np[cur][j];
            if (dp[cur] - 1 == dp[pos]) {
                ans += ('a' + j);
                cur = pos;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
