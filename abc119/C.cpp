
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    REP(i, N) cin >> l[i];

    int ans = INF;
    REP(i, 1 << (2 * N)) {
        int mp = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        REP(j, N) {
            int kind = (i >> (j * 2)) & 3;
            if (kind == 0) continue;
            if (kind == 1) {
                if (a > 0) mp += 10;
                a += l[j];
            }
            if (kind == 2) {
                if (b > 0) mp += 10;
                b += l[j];
            }
            if (kind == 3) {
                if (c > 0) mp += 10;
                c += l[j];
            }
        }
        if (a == 0 || b == 0 || c == 0) continue;
        mp += abs(A - a) + abs(B - b) + abs(C - c);
        ans = min(mp, ans);
    }
    cout << ans << endl;
    return 0;
}
