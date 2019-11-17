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

#define int long long
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

class FLaminate {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> H(N + 1);
        REP(i, N) cin >> H[i + 1];

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
        dp[0][0] = 0;
        FOR(i, 1, N) {
            FOR(j, 1, N) {
                int tmp = INF;
                REP(k, i) {
                    tmp = min(tmp, dp[k][j - 1] + max(0LL, H[i] - H[k]));
                }
                dp[i][j] = tmp;
            }
        }

        int res = INF;
        REP(i, N + 1) {
            res = min(res, dp[i][N - K]);
        }
        cout << res << endl;
    }
};
