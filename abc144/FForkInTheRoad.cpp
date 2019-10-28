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

class FForkInTheRoad {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;
    map<P, int> path;
    int N, M;
    vector<double> dp;

    double calc(int v) {
        dp[N - 1] = 0;
        for (int i = N - 1; i >= 0; i--) {
            int num = G[i].size();
            if (num >= 2 && i == v) {
                num--;
            }

            double sum = 0;
            double maxv = -1;
            REP(j, G[i].size()) {
                int to = G[i][j];
                sum += dp[to] / num;
                maxv = max(maxv, dp[to]);
            }
            if (G[i].size() != num) {
                sum -= maxv / num;
            }

            dp[i] = sum + 1;
        }

        return dp[0] - 1;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        G.resize(N), dp.resize(N);

        REP(i, M) {
            int s, t;
            cin >> s >> t;
            s--, t--;
            G[s].push_back(t);
            path[{s, t}] = i;
        }

        double res = INF;
        REP(i, N) {
            res = min(res, calc(i));
        }

        fcout << res << endl;
    }
};
