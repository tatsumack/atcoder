
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

//　行列累乗

typedef vector<int> Vec;
typedef vector<Vec> Mat;

int add(int a, int b) {
    return a ^ b;
}

int mul(int a, int b) {
    return a & b;
}

Vec mulMatVec(Mat a, Vec b) {
    int n = b.size();
    Vec ret(n, 0);
    REP(i, n)REP(j, n)ret[i] = add(ret[i], mul(a[i][j], b[j]));
    return ret;
}

Mat mulMatMat(Mat a, Mat b) {
    int n = a.size();
    Mat ret(n, Vec(n, 0));
    REP(i, n)REP(j, n)REP(k, n) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
    return ret;
}

Mat fastPow(Mat x, int n) {
    Mat ret(x.size(), Vec(x.size(), 0));
    REP(i, x.size()) ret[i][i] = -1;
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, M;
    cin >> K >> M;

    Vec A(K), C(K);
    REP(i, K) cin >> A[i];
    REP(i, K) cin >> C[i];

    if (M <= K) {
        cout << A[M - 1] << endl;
        return 0;
    }

    std::reverse(A.begin(), A.end());

    Mat m(K, Vec(K));
    REP(i, K) {
        REP(j, K) {
            if (i == 0) {
                m[i][j] = C[j];
            } else {
                // -1なのは全bit1にするため
                m[i][j] = (i == j + 1) ? -1 : 0;
            }
        }
    }

    auto mm = fastPow(m, M - K);
    auto ans = mulMatVec(mm, A);
    cout << ans[0] << endl;

    return 0;
}
