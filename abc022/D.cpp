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

int N, AX[100005], AY[100005], BX[100005], BY[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) cin >> AX[i] >> AY[i];
    REP(i, N) cin >> BX[i] >> BY[i];

    double agx = 0;
    double agy = 0;
    REP(i, N) {
        agx += AX[i];
        agy += AY[i];
    }
    agx /= N;
    agy /= N;

    double bgx = 0;
    double bgy = 0;
    REP(i, N) {
        bgx += BX[i];
        bgy += BY[i];
    }
    bgx /= N;
    bgy /= N;

    double ad = 0;
    REP(i, N) { ad = max(ad, sqrt(pow(AX[i] - agx, 2) + pow(AY[i] - agy, 2))); }
    double bd = 0;
    REP(i, N) { bd = max(bd, sqrt(pow(BX[i] - bgx, 2) + pow(BY[i] - bgy, 2))); }
    printf("%.10f\n", bd / ad);

    return 0;
}
