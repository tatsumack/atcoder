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

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

class DSwapAndFlip {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];

        vector<vector<int>> dp(1LL << N, vector<int>(51, INF));
        dp[0][0] = 0;
        REP(i, N) {
            REP(s, 1LL << N) {
                int b = 0;
                REP(j, N) {
                    if (s >> j & 1) b++;
                }
                if (b != i) continue;
                REP(j, N) {
                    if (s >> j & 1) continue;
                    int val = 0;
                    FOR(jj, j + 1, N - 1) {
                        if (s >> jj & 1) val++;
                    }
                    int dis = abs(i - j) % 2;
                    int v = dis % 2 == 0 ? A[j] : B[j];
                    REP(k, 51) {
                        if (dp[s][k] == INF) continue;
                        if (v < k) continue;
                        dp[s | (1LL << j)][v] = min(dp[s | (1LL << j)][v], dp[s][k] + val);
                    }
                }
            }
        }
        int res = INF;
        REP(j, 51) {
            res = min(res, dp[(1LL << N) - 1][j]);
        }
        if (res == INF) res = -1;
        cout << res << endl;

    }
};
