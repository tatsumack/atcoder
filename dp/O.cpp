
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
    if (a >= mod)
        a -= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    REP(i, N) {
        REP(j, N) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(N+1, vector<int>(1 << N));
    dp[0][0] = 1;
    REP(i, N) {
        REP(k, 1 << N) {
            if (dp[i][k] == 0) continue;

            bitset<25> bs(k);
            if (bs.count() != i) continue;

            REP(j, N) {
                if (a[i][j] == 0) continue;
                if (bs[j]) continue;
                add(dp[i + 1][k | (1 << j)], dp[i][k]);
            }
        }
    }
    cout << dp[N][(1 << N) - 1] << endl;

    return 0;
}
