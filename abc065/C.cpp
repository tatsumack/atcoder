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
#define REV(i, a) for (int i = (a); i > 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, M;
int fac[100005];
int mod = 1000000007;

signed main() {
    cin >> N >> M;
    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return 0;
    }

    fac[0] = fac[1] = 1;
    FOR(i, 2, max(N, M) + 2) { fac[i] = (fac[i - 1] * i) % mod; }

    int ans = (fac[N] * fac[M]) % mod;
    if (N == M) ans *= 2;
    cout << ans % mod << endl;

    return 0;
}
