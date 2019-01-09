
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


int dp[3005][3005];
string s, t;

void getLCS(int i, int j, string& res) {
    if (i == 0 || j == 0) return;
    if (s[i - 1] == t[j - 1]) {
        res = s[i - 1] + res;
        return getLCS(i - 1, j - 1, res);
    }

    if (dp[i - 1][j] >= dp[i][j - 1]) {
        getLCS(i - 1, j, res);
    } else {
        getLCS(i, j - 1, res);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> t;

    CLR(dp, 0);

    FOR(i, 1, s.size()) {
        FOR(j, 1, t.size()) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans;
    getLCS(s.size(), t.size(), ans);
    cout << ans << endl;

    return 0;
}
