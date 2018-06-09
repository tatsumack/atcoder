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

const long double EPS = 1e-10;

using namespace std;

int N;
int x[2005], y[2005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];

    int right = 0;
    int acutes = 0;
    int index = 0;
    REP(i, N) {
        vector<long double> angles;
        REP(j, N) {
            if (i == j) continue;
            long double angle = atan2(y[j] - y[i], x[j] - x[i]);
            angles.push_back(angle);
        }
        sort(angles.begin(), angles.end());
        REP(j, N - 1) { angles.push_back(angles[j] + 2.0 * M_PI); }

        int r = 0;
        REP(l, N - 1) {
            while (r + 1 < angles.size() &&
                   angles[r + 1] - angles[l] < M_PI / 2.0 - EPS) {
                r++;
            }
            acutes += r - l;
            if (r + 1 < angles.size() &&
                angles[r + 1] - angles[l] < M_PI / 2.0 + EPS) {
                right++;
            }
            if (l == r) r++;
        }
    }

    int all = N * (N - 1) * (N - 2) / 6;
    int obtuse = 3 * all - acutes - right;
    acutes = all - right - obtuse;
    cout << acutes << " " << right << " " << obtuse << endl;

    return 0;
}
