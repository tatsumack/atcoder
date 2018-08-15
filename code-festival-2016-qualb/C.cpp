
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

    int W, H;
    cin >> W >> H;
    vector<int> p(W), q(H);
    REP(i, W) cin >> p[i];
    REP(i, H) cin >> q[i];
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    int ans = 0;
    int ip, iq;
    ip = iq = 0;
    while (ip < W || iq < H) {
        if (ip >= W) {
            ans += q[iq] * (W + 1 - ip);
            iq++;
        } else if (iq >= H) {
            ans += p[ip] * (H + 1 - iq);
            ip++;
        } else if (q[iq] <= p[ip]) {
            ans += q[iq] * (W + 1 - ip);
            iq++;
        } else {
            ans += p[ip] * (H + 1 - iq);
            ip++;
        }
    }
    cout << ans << endl;

    return 0;
}
