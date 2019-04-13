
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

int binpow(int x, int p) {
    if (p == 0) return 1;

    if (p % 2 == 0)
        return binpow((x * x) % mod, p / 2);
    else
        return (x * binpow(x, p - 1)) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X;
    cin >> N >> X;

    vector<int> S(N);
    REP(i, N) cin >> S[i];

    sort(S.begin(), S.end());

    map<int, int> path;
    REP(i, S.size()) {
        int n = X % S[i];
        auto itr = lower_bound(S.begin(), S.end(), n);
        if (itr != S.begin())
        path[i] = t;
    }

    vector<int> fac(N), rev(N);
    fac[0] = 1;
    FOR(i, 1, N - 1) fac[i] = fac[i - 1] * i;

    rev[N - 1] = binpow(fac[N - 1], mod - 2) % mod;
    REV(i, N - 2, 0) { rev[i] = (rev[i + 1] * (i + 1)) % mod; }

    int ans = 0;
    REP(i, S.size()) {
        int n = S[i];
        int count = 0;
        int res = X % n;
        int pos = i;
        while (pos > 0) {
            count++;
            pos = path[pos];
            n = S[pos];
            res = res % n;
        }

        int tmp = (res * (fac[N - 1] * rev[count]) % mod) % mod;
        ans = (ans + tmp) % mod;
    }
    cout << ans << endl;

    return 0;
}
