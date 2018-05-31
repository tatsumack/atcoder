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

int N, M, F[100005], dp[100005];
int mod = 1e9 + 7;

int fac[100005], rev[100005];

int binpow(int x, int p) {
    if (p == 0) return 1;

    if (p % 2 == 0)
        return binpow((x * x) % mod, p / 2);
    else
        return (x * binpow(x, p - 1)) % mod;
}

int nCr(int n, int r) {
    if (r > n) return 0;
    return ((fac[n] * rev[r]) % mod * rev[n - r]) % mod;
}

void precalc(int n) {
    fac[0] = fac[1] = 1;
    FOR(i, 2, n + 2)
    fac[i] = (fac[i - 1] * i) % mod;

    rev[n + 1] = binpow(fac[n + 1], mod - 2) % mod;
    REV(i, n, 0) { rev[i] = (rev[i + 1] * (i + 1)) % mod; }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    precalc(100005);

    cin >> N >> M;
    REP(i, N) cin >> F[i];

    set<int> s;
    int r = 0;
    int ans = 0;
    c[0] = 1;
    REP(l, N) {
        while (r < N && s.count(F[r]) == 0) {
            s.insert(F[r]);
            r++;
        }
        int tmp = 0;
        REP(j, r - l) { tmp = (tmp + nCr(r - l - 1, j)) % mod; }
        if (l > 0) tmp = (tmp * c[l - 1]) % mod;
        ans = (ans + tmp) % mod;
        DUMP(ans)

        c[r - 1] = tmp;

        l == r ? r++ : s.erase(F[l]);
    }
    cout << ans << endl;

    return 0;
}
