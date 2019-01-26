
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;

int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

// 桁DP
int dp[10007][110][2]; // dp[i][j][k]: i:桁 j:総和の余り k:K以下が確定しているか 0:no, 1:yes

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string K;
    int D;
    cin >> K;
    cin >> D;

    CLR(dp, 0);

    dp[0][0][0] = 1;
    REP(i, K.size()) {
        REP(j, D) {
            REP(k, 2) {
                int num = K[i] - '0';
                int t = k ? 9 : num;
                REP(d, t + 1) {
                    add(dp[i + 1][(j + d) % D][k || (d < num)], dp[i][j][k]);
                }
            }
        }
    }

    int ans = 0;
    REP(k, 2) add(ans, dp[K.size()][0][k]);
    cout << (ans - 1 + mod) % mod << endl;

    return 0;
}
