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

class EAllYouCanEat {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }


    void solve(std::istream& cin, std::ostream& cout) {
        int N, T;
        cin >> N >> T;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i] >> B[i];

        vector<P> v(N);
        REP(i, N) {
            v[i] = {A[i], B[i]};
        }
        sort(v.begin(), v.end());

        vector<vector<int>> dp(N + 1, vector<int>(T + 1));
        REP(i, N) {
            REP(j, T) {
                int a = v[i].first;
                int b = v[i].second;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                int nt = min(T, j + a);
                dp[i + 1][nt] = max(dp[i + 1][nt], dp[i][j] + b);
            }
            dp[i + 1][T] = max(dp[i + 1][T], dp[i][T]);
        }

        int res = 0;
        REP(j, T + 1) {
            res = max(res, dp[N][j]);
        }
        cout << res << endl;
    }
};
