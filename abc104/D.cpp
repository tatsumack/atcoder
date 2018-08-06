
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

int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int three[100005];
    three[0] = 1;
    REP(i, 100001) {
        three[i + 1] = (three[i] * 3) % mod;
    }

    string S;
    cin >> S;
    int n = S.size();
    vector<int> A(n+10);
    vector<int> C(n+10);
    vector<int> Q(n+10);

    REPS(i, n) {
        A[i] = A[i - 1];
        C[i] = C[i - 1];
        Q[i] = Q[i - 1];
        char c = S[i - 1];
        switch (c) {
            case 'A':
                A[i]++;
                break;
            case 'C':
                C[i]++;
                break;
            case '?':
                Q[i]++;
                break;
        }
    }

    int ans = 0;
    REPS(i, n) {
        char c = S[i - 1];
        if (c == 'A' || c == 'C') continue;
        int la = A[i];
        int rc = C[n] - C[i];
        int lq = Q[i];
        int rq = Q[n] - Q[i];
        int sumq = Q[n];
        if (c == 'B') {
            ans += ((la * rc) % mod * three[sumq]) % mod;
            if (sumq >= 1) ans += ((la * rq) % mod * three[sumq - 1]) % mod;
            if (sumq >= 1) ans += ((rc * lq) % mod * three[sumq - 1]) % mod;
            if (sumq >= 2) ans += ((lq * rq) % mod * three[sumq - 2]) % mod;
        }
        if (c == '?') {
            lq--;
            ans += ((la * rc) % mod * three[sumq - 1]) % mod;
            if (sumq >= 2) ans += ((la * rq) % mod * three[sumq - 2]) % mod;
            if (sumq >= 2) ans += ((rc * lq) % mod * three[sumq - 2]) % mod;
            if (sumq >= 3) ans += ((lq * rq) % mod * three[sumq - 3]) % mod;
        }
    }
    cout << ans % mod << endl;

    return 0;
}
