
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);
    vector<int> h(N);
    REP(i, N) cin >> x[i] >> y[i] >> h[i];

    int ansx = -1;
    int ansy = -1;
    int H = -1;
    REP(cx, 101) {
        REP(cy, 101) {
            H = -1;
            REP(i, N) {
                if (h[i] == 0) continue;

                int th = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                if (th < 1) {
                    H = -1;
                    break;
                }

                if (H != -1 && th != H) {
                    H = -1;
                    break;
                }
                H = th;
            }
            if (H < 1) continue;
            REP(i, N) {
                if (h[i] > 0) continue;
                int th = H - abs(x[i] - cx) - abs(y[i] - cy);
                if (th > 0) {
                    H = -1;
                    break;
                }
            }
            if (H < 1) continue;

            ansx = cx;
            ansy = cy;
            break;
        }
        if (H >= 1) {
            break;
        }
    }
    cout << ansx << " " << ansy << " " << H << endl;

    return 0;
}
