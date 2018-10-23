
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

    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    int p = abs(X[0] + Y[0]) % 2;
    REP(i, N) {
        if (abs(X[i] + Y[i]) % 2 != p) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> d;
    REV(i, 30, 0) {
        d.push_back(1 << i);
    }
    if (p == 0) d.push_back(1);

    cout << d.size() << endl;
    REP(i, d.size()) {
        cout << d[i] << " ";
    }
    cout << endl;

    REP(i, N) {
        int x = 0;
        int y = 0;
        int gx = X[i];
        int gy = Y[i];

        REP(j, d.size()) {
            if (abs(x - gx) > abs(y - gy)) {
                if (x - gx > 0) {
                    x -= d[j];
                    cout << "L";
                }
                else {
                    x += d[j];
                    cout << "R";
                }
            }
            else {
                if (y - gy > 0) {
                    y -= d[j];
                    cout << "D";
                }
                else {
                    y += d[j];
                    cout << "U";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
