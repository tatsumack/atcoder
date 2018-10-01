
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string>
            R(31);
    vector<string>
            L(31);
    vector<string>
            U(31);
    vector<string>
            D(31);

    R[0] = "R";
    L[0] = "L";
    U[0] = "U";
    D[0] = "D";
    REP(i, 30) {
        R[i + 1] = R[i] + R[i];
        DUMP(R[i+1])
    }
    REP(i, 30) L[i + 1] = L[i] + L[i];
    REP(i, 30) U[i + 1] = U[i] + U[i];
    REP(i, 30) D[i + 1] = D[i] + D[i];
    DUMP("hoge")


    vector<int> x(n);
    vector<int> y(n);
    REP(i, n) cin >> x[i] >> y[i];

    int m = 0;
    int test = (abs(x[0]) + abs(y[0])) % 2;
    REP(i, n) {
        if ((abs(x[i]) + abs(y[i])) % 2 != test) {
            cout << -1 << endl;
            return 0;
        }

        m = max(m, abs(x[i]) + abs(y[i]));
    }

    cout << m << endl;
    REP(i, m) {
        if (i != 0) cout << " ";
        cout << 1;
    }
    cout << endl;
    REP(i, n) {
        auto xc = x[i] > 0 ? R : L;
        auto yc = y[i] > 0 ? U : D;

        string res;
        res.reserve(m+1);
        REP(i, 30) {
            if (abs(x[i]) >> i & 1) res += xc[i];
            if (abs(y[i]) >> i & 1) res += yc[i];
        }

        int left = (m - res.size()) / 2;
        REP(i, 30) {
            if (left >> i & 1) res += R[i] + L[i];
        }
        cout << res << endl;
    }

    return 0;
}
