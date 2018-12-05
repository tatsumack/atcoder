
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

int mod = 1e9 + 7;

// mod
void add(int& a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

// nCr
int fac[2005], rev[2005];

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

    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    precalc(N);

    vector<vector<int>> dp(B + 2, vector<int>(N + 1, 0));
    dp[A][0] = 1;
    for (int k = A; k <= B; k++) {
        for (int n = 0; n <= N; n++) {
            add(dp[k + 1][n], dp[k][n]);

            int v = 1;
            for (int i = 1; n + i * k <= N && i <= D; i++) {
                v *= nCr(N - n - k * (i - 1), k);
                v %= mod;
                if (i < C) continue;
                add(dp[k + 1][n + i * k], (((dp[k][n] * v) % mod) * rev[i]) % mod);
            }
        }
    }
    cout << dp[B + 1][N] << endl;
    return 0;
}
