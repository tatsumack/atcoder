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

int dp[200005][2];

class ADividingAString {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        CLR(dp, 0);

        string s;
        cin >> s;

        int N = s.size();

        dp[0][0] = 1;
        FOR(i, 1, N - 1) {
            if (s[i] != s[i - 1]) {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            if (i >= 2) {
                dp[i][1] = dp[i - 2][0] + 1;
            }
        }
        cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
    }
};
