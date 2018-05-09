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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int H, W;
int ans = INF;

void solve(int th, int tw) {
    REPS(i, th - 1) {
        int a1 = i * tw;
        int h = th - i;
        if (h % 2 == 0) {
            ans = min(ans, abs(a1 - h / 2 * tw));
        } else if (tw % 2 == 0) {
            ans = min(ans, abs(a1 - tw / 2 * h));
        } else {
            int a2 = max(h, tw) / 2 * min(h, tw);
            int a3 = (max(h, tw) / 2 + 1) * min(h, tw);
            ans = min(ans, abs(max(a1, a3) - min(a1, a2)));
        }
        DUMP(h);
        DUMP(ans);
    }
}

signed main() {
    cin >> H >> W;

    solve(H, W);
    solve(W, H);
    cout << ans << endl;

    return 0;
}
