
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

int p[20][20];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        p[x][y] = 1;
        p[y][x] = 1;
    }

    int ans = 0;
    REP(i, 1 << N) {
        vector<int> mem;
        REP(j, N) {
            if (i >> j & 1) {
                mem.push_back(j);
            }
        }

        bool ok = true;
        REP(i, mem.size()) {
            REP(j, mem.size()) {
                if (i == j) continue;
                if (p[mem[i]][mem[j]] == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            ans = max(ans, (int)mem.size());
        }
    }
    cout << ans << endl;


    return 0;
}
