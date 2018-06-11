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

int N, C, D[50][50], c[505][505];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    REPS(i, C) REPS(j, C) { cin >> D[i][j]; }
    REP(i, N) REP(j, N) { cin >> c[i][j]; }

    map<int, map<int, int> > cmap;
    REP(i, N) REP(j, N) { cmap[(i + j) % 3][c[i][j]]++; }

    int ans = INF;
    REPS(i, C) {
        REPS(j, C) {
            if (i == j) continue;
            REPS(k, C) {
                if (j == k || i == k) continue;

                int tmp = 0;
                REPS(t, C)
                tmp += cmap[0][t] * D[t][i];
                REPS(t, C)
                tmp += cmap[1][t] * D[t][j];
                REPS(t, C)
                tmp += cmap[2][t] * D[t][k];

                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
