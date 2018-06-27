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

bool is_intersected(int ax, int ay, int bx, int by, int cx, int cy, int dx,
                    int dy) {
    int ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    int tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    int tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    int td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

    return tc * td < 0 && ta * tb < 0;
}

int N, ax, ay, bx, by, x[200], y[200];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> ax >> ay >> bx >> by;
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];
    x[N] = x[0];
    y[N] = y[0];

    int num = 0;
    REP(i, N) {
        if (is_intersected(ax, ay, bx, by, x[i], y[i], x[i + 1], y[i + 1]))
            num++;
    }
    cout << num / 2 + 1 << endl;

    return 0;
}
