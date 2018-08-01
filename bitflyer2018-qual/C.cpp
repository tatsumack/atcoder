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
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N, D, X[100005], L[100005], R[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;
    REP(i, N) cin >> X[i];

    int r = 0;
    REP(i, N) {
        while (r + 1 < N && X[r + 1] - X[i] <= D) {
            r++;
        }
        R[i] = r - i;
        if (i == r) r++;
    }

    int l = N - 1;
    REV(i, N - 1, 0) {
        while (l - 1 >= 0 && X[i] - X[l - 1] <= D) {
            l--;
        }
        L[i] = i - l;
        if (i == l) l--;
    }

    int ans = 0;
    REP(i, N) ans += L[i] * R[i];
    REP(i, N) ans -= (R[i] * (R[i] - 1)) / 2;
    cout << ans << endl;

    return 0;
}
