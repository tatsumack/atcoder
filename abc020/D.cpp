
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

typedef pair<int, int> P;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a * b * gcd(a, b); }

int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void sub(int& a, int b) {
    a %= mod;
    b %= mod;
    a -= b;
    if (a < 0) a += mod;
}

// 素因数
vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        s.push_back(i);
        while (a % i == 0) a /= i;
    }
    if (a > 1) s.push_back(a);
    return s;
}

int modinv(int a, int m) {
    int b = m, u = 1, v = 0;
    while (b) {
        int t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> div;
    for (int i = 1; i * i <= K; ++i) {
        if (K % i == 0) {
            div.push_back(i);
            if (i != K / i) div.push_back(K / i);
        }
    }

    int inv2 = modinv(2, mod);

    int ans = 0;
    REP(i, div.size()) {
        int d = div[i];
        int k = K / d;
        int n = N / d;
        auto facs = getPrimeFactors(k);
        int tmp = 0;
        REP(j, 1 << facs.size()) {
            int mul = 1;

            int cnt = 0;
            REP(k, facs.size()) {
                if (j >> k & 1) {
                    mul *= facs[k];
                    cnt++;
                }
            }

            int dd = n / mul;
            int f = mul % mod;
            int l = (dd * mul) % mod;
            int a = (f + l) % mod;
            int sum = (a * dd) % mod;
            sum *= inv2 % mod;
            sum %= mod;

            if (cnt % 2 == 1) {
                sub(tmp, sum);
            } else {
                add(tmp, sum);
            }
        }
        add(ans, tmp);
    }

    ans *= K;
    ans %= mod;

    cout << ans << endl;


    return 0;
}
