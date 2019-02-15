
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

int mod = 1e9 + 7;

int fac[200005], rev[200005];

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
    FOR(i, 2, n + 2)fac[i] = (fac[i - 1] * i) % mod;

    rev[n + 1] = binpow(fac[n + 1], mod - 2) % mod;
    REV(i, n, 0) { rev[i] = (rev[i + 1] * (i + 1)) % mod; }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precalc(1000);

    int R, C, X, Y, D, L;
    cin >> R >> C >> X >> Y >> D >> L;

    int num = 0;
    REP(i, R) {
        REP(j, C) {
            if (i + X <= R && j + Y <= C) {
                num += 1;
                num %= mod;
            }
        }
    }

    int res = 0;
    REP(i, 1 << 4) {
        int bnum = 0;
        int tx = X;
        int ty = Y;
        if (i >> 0 & 1) tx--, bnum++;
        if (i >> 1 & 1) tx--, bnum++;
        if (i >> 2 & 1) ty--, bnum++;
        if (i >> 3 & 1) ty--, bnum++;
        if (tx < 0 || ty < 0) continue;

        int tmp = (nCr(tx * ty, D) * nCr(tx * ty - D, L)) % mod;
        if (bnum % 2 == 0) {
            res += tmp;
            res %= mod;
        } else {
            res -= tmp;
            if (res < 0) res += mod;
        }
    }

    cout << (res * num) % mod << endl;

    return 0;
}
