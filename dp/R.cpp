
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


// mod
int mod = 1e9 + 7;

int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }

int mul(int x, int y) { return 1LL * x * y % mod; }

// 行列累乗
typedef vector<int> Vec;
typedef vector<Vec> Mat;

Vec mulMatVec(Mat a, Vec b) {
    int n = b.size();
    Vec ret(n, 0);
    REP(i, n)REP(j, n)ret[i] = add(ret[i], mul(a[i][j], b[j]));
    return ret;
}

Mat mulMatMat(Mat a, Mat b) {
    int n = a.size();
    Mat ret(n, Vec(n, 0));
    REP(i, n)REP(j, n)REP(k, n)ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
    return ret;
}

Mat fastPow(Mat x, int n) {
    Mat ret(x.size(), Vec(x.size(), 0));
    REP(i, x.size())ret[i][i] = 1;
    while (0 < n) {
        if ((n % 2) == 0) {
            x = mulMatMat(x, x);
            n >>= 1;
        } else {
            ret = mulMatMat(ret, x);
            --n;
        }
    }
    return ret;
}

void printVec(Vec a) {
    cout << "[\t";
    REP(i, a.size())cout << a[i] << "\t";
    cout << "]" << endl;
}

void printMat(Mat a) {
    REP(i, a.size())printVec(a[i]);
}

/////////////////////////////////////



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    Mat a(N, Vec(N));
    REP(i, N) REP(j, N) cin >> a[i][j];

    a = fastPow(a, K);

    Vec v(N, 1);
    v = mulMatVec(a, v);

    int ans = 0;
    REP(i, N) ans = add(ans, v[i]);
    cout << ans << endl;

    return 0;
}
