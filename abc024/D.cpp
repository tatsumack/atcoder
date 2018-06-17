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
int mod = 1e9 + 7;

int A, B, C;

int binpow(int x, int p) {
    if (p == 0) return 1;

    if (p % 2 == 0)
        return binpow((x * x) % mod, p / 2);
    else
        return (x * binpow(x, p - 1)) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    int tc1 = ((B * C) % mod - (A * B) % mod + mod) % mod;
    int tc2 =
        ((((A * C) % mod - (B * C) % mod) % mod) + (A * B) % mod + mod) % mod;
    int c = (tc1 * binpow(tc2, mod - 2)) % mod;

    int tr1 = ((B * C) % mod - (A * C) % mod + mod) % mod;
    int tr2 =
        ((((A * B) % mod - (B * C) % mod) % mod) + (A * C) % mod + mod) % mod;
    int r = (tr1 * binpow(tr2, mod - 2)) % mod;
    cout << r << " " << c << endl;

    return 0;
}
