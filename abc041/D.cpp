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
#define INF (3e15)

using namespace std;

int N, M, E[20][20], dp[70000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        E[x][y] = 1;
    }

    dp[0] = 1;
    REP(state, 1 << N) {
        REP(i, N) {
            // iがstateに含まれていない
            if (state & 1 << i) continue;

            // iからstateに有向辺が含まれていない
            bool ok = true;
            REP(k, N) {
                if (state & 1 << k && E[i + 1][k + 1] == 1) ok = false;
            }
            if (!ok) continue;

            dp[state | 1 << i] += dp[state];
        }
    }
    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
