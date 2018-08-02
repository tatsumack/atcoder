
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

int N, L, A[100005], sum[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;
    REP(i, N) cin >> A[i];

    int t = -1;
    REP(i, N - 1) {
        if (A[i] + A[i+1] >= L)
        {
            t = i;
            break;
        }
    }
    if (t == -1)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    FOR(i, 1, N-1) {
        if (i >= t+1) break;
        cout << i << endl;
    }
    REV(i, N-1, 1) {
        if (i <= t) break;
        cout << i << endl;
    }
    return 0;
}
