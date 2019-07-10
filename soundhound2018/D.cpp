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

int dp[15][50005];
int L[15][500005];
int R[15][500005];
int P[15][500005];
int F[15][500005];

class D {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int H, W;

    void init() {
        CLR(dp, 0);
        CLR(L, 0);
        CLR(R, 0);
        CLR(P, 0);
        CLR(F, 0);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        init();
        cin >> H >> W;
        REP(i, H) REP(j, W) cin >> P[i][j];
        REP(i, H) REP(j, W) cin >> F[i][j];

        REP(h, H) {
            int cur = 0;
            REP(w, W) {
                L[h][w] = cur;
                if (w == W - 1) break;
                cur += P[h][w] - F[h][w] - F[h][w + 1];
                if (cur < 0) cur = 0;
            }
            cur = 0;
            REV(w, W - 1, 0) {
                R[h][w] = cur;
                if (w == 0) break;
                cur += P[h][w] - F[h][w] - F[h][w - 1];
                if (cur < 0) cur = 0;
            }
        }

        REP(h, H + 1) {
            REP(w, W) {
                dp[h][w] = -INF;
            }
        }
        dp[0][0] = 0;

        REP(h, H) {
            int tmp = -INF;
            REP(w, W) {
                tmp = max(tmp, dp[h][w] + P[h][w] - F[h][w] + L[h][w]);
                dp[h + 1][w] = max(dp[h + 1][w], tmp + R[h][w]);
                tmp += P[h][w + 1] - F[h][w + 1];
            }
            tmp = -INF;
            REV(w, W - 1, 0) {
                tmp = max(tmp, dp[h][w] + P[h][w] - F[h][w] + R[h][w]);
                dp[h + 1][w] = max(dp[h + 1][w], tmp + L[h][w]);
                if (w == 0) break;
                tmp += P[h][w - 1] - F[h][w - 1];
            }
        }
        REP(w, W) {
            cout << dp[H][w] << endl;
        }
    }
};
