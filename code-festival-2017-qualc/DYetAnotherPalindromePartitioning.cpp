#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1000005
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class DYetAnotherPalindromePartitioning {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;

        int n = s.size();
        vector<int> dp(1 << 26), ans(n);
        REP(i, 1 << 26) dp[i] = INF;
        dp[0] = 0;
        int x = 0;
        REP(i, n) {
            int c = s[i] - 'a';
            x ^= 1 << c;

            int val = INF;
            val = min(val, dp[x]);
            REP(j, 26) {
                int nx = x ^(1 << j);
                val = min(val, dp[nx]);
            }
            dp[x] = min(dp[x], val + 1);
            ans[i] = val + 1;
        }

        cout << ans[n - 1] << endl;
    }
};
