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

int H, M, S, C1, C2;
int c1, c2;

void deg(int t, int& dh, int& dm, int& ds) {
    int h = t / 3600 % 12;
    int m = t / 60 % 60;
    int s = t % 60;

    int all = 360 * 120;

    dh = all / 12 * h + all / (12 * 60) * m + s;
    dm = all / 60 * m + all / (60 * 60) * s;
    ds = all / 60 * s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> M >> S >> C1 >> C2;
    int t = H * 3600 + M * 60 + S;
    int dt = 0;

    int mint = INF;
    int maxt = -1;
    while (c1 <= C1 && c2 <= C2) {
        maxt = max(maxt, dt);
        dt++;
        int cur = t + dt;

        int ch, cm, cs;
        int ph, pm, ps;

        deg(cur, ch, cm, cs);
        deg(cur - 1, ph, pm, ps);

        if (ps < pm && cm <= cs) c1++;
        if (pm < ph && ch <= cm) c2++;

        if (c1 == C1 && c2 == C2 && cm != cs && ch != cm) {
            mint = min(mint, dt);
        }
    }

    if (c1 < C1 || c2 < C2) {
        cout << -1 << endl;
        return 0;
    }

    cout << mint << " " << maxt << endl;

    return 0;
}
