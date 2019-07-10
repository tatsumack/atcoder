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
#define fcout cout << fixed << setprecision(15)

using namespace std;

typedef pair<int, int> P;

class C1999 {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> A;
    vector<P> v;
    int memo[50][50];
    double p;
    map<int, int> winmap;
    int N;

    int nCr(int n, int r) {
        if (n < r) return 0;
        if (r == 0) return 1;
        if (n == r) return 1;
        if (memo[n][r] >= 0) return memo[n][r];
        return memo[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
    }

    // n が t 勝となる確率
    double f(int n, int t) {
        double res = 0;

        int s = winmap[n];
        REP(u, t + 1) {
            if (u > s) continue;
            double tmp = 1;
            REP(j, N - 1 - s - t + 2 * u) tmp *= p;
            REP(j, s + t - 2 * u) tmp *= (1 - p);
            tmp *= nCr(s, u);
            tmp *= nCr(N - 1 - s, t - u);
            res += tmp;
        }

        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        double x, y;
        char c;
        cin >> x >> c >> y;
        p = x / y;

        v.clear();
        winmap.clear();
        REP(i, N) {
            int win = 0;
            REP(j, N) {
                int a;
                cin >> a;
                win += a;
            }
            v.emplace_back(win, -i);
            winmap[i] = win;
        }
        sort(v.begin(), v.end());
        REP(i, v.size()) v[i].second *= -1;

        REP(i, 50) REP(j, 50) memo[i][j] = -1;

        vector<vector<double>> dp(N, vector<double>(N));
        REP(x, N) dp[0][x] = f(v.front().second, x);
        REP(i, N - 1) {
            int pre = v[i].second;
            int cur = v[i + 1].second;
            REP(x, N) {
                REP(y, N) {
                    if (x > y) continue;
                    if (x == y && cur > pre) continue;
                    dp[i + 1][y] += f(cur, y) * dp[i][x];
                }
            }
        }

        double res = 0;
        REP(x, N) res += dp[N - 1][x];
        fcout << res << endl;
    }
};
