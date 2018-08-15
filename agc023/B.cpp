
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<char> > S(N, vector<char>(N));
    REP(i, N) REP(j, N) cin >> S[i][j];

    int ans = 0;
    int a= 0;
    REP(b, N) {
        bool ok = true;
        REP(i, N) REP(j, N) {
                int x = i + a;
                int y = j + b;
                if (x >= N) x -= N;
                if (y >= N) y -= N;

                int rx = y;
                int ry = x;

                if (rx < a) rx += N;
                if (ry < b) ry += N;
                rx -= a;
                ry -= b;

                if (S[i][j] != S[rx][ry]) {
                    ok = false;
                    break;
                }
            }

        if (ok) ans++;
    }
    cout << ans * N << endl;
    return 0;
}
