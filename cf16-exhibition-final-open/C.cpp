
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

    vector<int> two(51);
    two[0] = 1;
    REP(i, 50) {
        two[i + 1] = 2 * two[i];
    }

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    int x = 0;
    REP(i, N) x ^= a[i];

    int ans = 0;
    REV(k, 30, 1) {
        if (((x >> (k - 1)) & 1) == 0) continue;
        REP(i, N) {
            if ((a[i] ^ a[i] - 1) == two[k] - 1) {
                ans++;
                x = x ^ a[i] ^ (a[i] - 1);
                break;
            }
        }
    }
    if (x != 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
