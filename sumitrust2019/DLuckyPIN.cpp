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

int dp[30005][11][11][11];

class DLuckyPIN {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }


    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        CLR(dp, 0);

        dp[0][10][10][10] = 1;
        REP(i, n) {
            int x = s[i] - '0';
            REP(h, 11) {
                REP(j, 11) {
                    REP(k, 11) {
                        dp[i + 1][h][j][k] = dp[i][h][j][k];
                        if (dp[i][h][j][k] > 0) {
                            dp[i+1][x][10][10]++;
                            dp[i+1][h][x][10]++;
                            dp[i+1][h][j][x]++;
                        }
                    }
                }
            }
        }

        int res = 0;
        REP(i, 10) REP(j, 10) REP(k, 10) {
                    if (dp[n][i][j][k] > 0) {
                        res++;
                    }
                }
                cout << res << endl;
    }
};
