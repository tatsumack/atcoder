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


int dp[81][81][26005];

class EBalancedPath {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        vector<vector<int>> b(h, vector<int>(w));
        vector<vector<int>> d(h, vector<int>(w));
        REP(i, h) REP(j, w) cin >> a[i][j];
        REP(i, h) REP(j, w) cin >> b[i][j];

        REP(i, h) {
            REP(j, w) {
                d[i][j] = abs(a[i][j] - b[i][j]);
            }
        }

        CLR(dp, 0);
        int offset = 13000;
        dp[0][1][offset]++;
        dp[1][0][offset]++;
        FOR(i, 1, h) {
            FOR(j, 1, w) {
                REP(k, 26000) {
                    if (dp[i - 1][j][k] > 0 || dp[i][j - 1][k] > 0) {
                        int nk = min(26000, k + d[i - 1][j - 1]);
                        dp[i][j][nk] = 1;
                        int nk2 = max(0, k - d[i - 1][j - 1]);
                        dp[i][j][nk2] = 1;
                    }
                }
            }
        }

        int res = INF;
        REP(k, 26000) {
            if (dp[h][w][k]) {
                res = min(res, abs(k - offset));
            }
        }
        cout << res << endl;
    }
};
