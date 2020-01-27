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

class ECrestedIbisVsMonster {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, N;
        cin >> H >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i] >> B[i];

        vector<int> dp(H+1);
        REP(i, H+1) dp[i] = INF;
        dp[H] = 0;
        REV(i, H, 0) {
            REP(j, N) {
                int nj = max(0LL, i - A[j]);
                dp[nj] = min(dp[nj], dp[i] + B[j]);
            }
        }
        cout << dp[0] << endl;
    }
};
