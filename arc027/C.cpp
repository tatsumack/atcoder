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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

int dp[305][305][605];

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int x, y, n;
        cin >> x >> y >> n;
        vector<int> t(n), h(n);
        REP(i, n) {
            cin >> t[i] >> h[i];
        }

        CLR(dp, 0);
        int s = x + y;
        REP(i, n) {
            REP(j, 301) {
                REP(k, 601) {
                    // 買わない
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    // 買う
                    if (j + 1 <= x && k + t[i] <= s) {
                        dp[i + 1][j + 1][k + t[i]] = max(dp[i + 1][j + 1][k + t[i]], dp[i][j][k] + h[i]);
                    }
                }
            }
        }
        int res = 0;
        REP(j, 301) {
            REP(k, 601) {
                res = max(res, dp[n][j][k]);
            }
        }
        cout << res << endl;
    }
};
