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

class EGetEverything {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> a(M);
        vector<int> c(M);
        REP(i, M) {
            int b;
            cin >> a[i] >> b;
            REP(j, b) {
                int cc;
                cin >> cc;
                c[i] |= 1 << (cc - 1);
            }
        }

        vector<vector<int>> dp(M + 1, vector<int>(1 << N, INF));
        dp[0][0] = 0;
        REP(i, M) {
            REP(j, 1 << N) {
                int cc = c[i];
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                dp[i+1][j | cc] = min(dp[i+1][j | cc], dp[i][j] + a[i]);
            }
        }

        int ans = dp[M][(1 << N) - 1];
        if (ans == INF) {
            cout << -1 << endl;
            return;
        }
        cout << ans << endl;
    }
};
