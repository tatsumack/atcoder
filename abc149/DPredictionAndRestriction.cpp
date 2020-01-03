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

class DPredictionAndRestriction {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, k, r, s, p;
        cin >> n >> k >> r >> s >> p;
        string t;
        cin >> t;

        int score[3] = {r, s, p};
        map<char, int> m = {
                {'r', 0},
                {'s', 1},
                {'p', 2},
        };

        vector<vector<int>> dp(n, vector<int>(3));
        REP(i, n) {
            char c = t[i];
            int to = (m[c] + 2) % 3;
            if (i < k) {
                dp[i][to] += score[to];
            } else {
                REP(j, 3) {
                    int o1 = (j + 1) % 3;
                    int o2 = (j + 2) % 3;
                    dp[i][j] = max(dp[i - k][o1], dp[i - k][o2]);
                    if (j == to) {
                        dp[i][j] += score[j];
                    }
                }
            }
        }

        int res = 0;
        REV(i, n - 1, max(0LL, n - k)) {
            res += max({dp[i][0], dp[i][1], dp[i][2]});
        }
        cout << res << endl;
    }
};
