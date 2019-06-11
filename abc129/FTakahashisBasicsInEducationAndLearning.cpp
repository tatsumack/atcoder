#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

int mod;

//　行列累乗
typedef vector<int> Vec;
typedef vector<Vec> Mat;

int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }

int mul(int x, int y) { return 1LL * x * y % mod; }

Vec mulMatVec(Mat a, Vec b) {
    int n = b.size();
    Vec ret(n, 0);
    REP(i, n)REP(j, n)ret[i] = add(ret[i], mul(a[i][j], b[j]));
    return ret;
}

Vec mulVecMat(Vec a, Mat b) {
    int n = a.size();
    Vec ret(n, 0);
    REP(i, n)REP(j, n) ret[i] = add(ret[i], mul(a[j], b[j][i]));
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

class FTakahashisBasicsInEducationAndLearning {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int L, A, B;
        cin >> L >> A >> B >> mod;

        vector<int> ten(19);
        ten[0] = 1;
        FOR(i, 1, 18) ten[i] = (ten[i - 1] * 10) % mod;

        vector<int> cnt(19);
        int d = 1;
        FOR(i, 1, 18) {
            int next = d * 10 - 1;
            if (A <= next) {
                cnt[i] = min((next - A) / B + 1, L);
            }
            d *= 10;
        }

        Mat m = {
                {1, 0, 0},
                {0, 1, 0},
                {0, 0, 1},
        };
        FOR(i, 1, 18) {
            int num = cnt[i] - cnt[i - 1];
            Mat mat = {
                    {ten[i], 0,       0},
                    {1,      1,       0},
                    {0,      B % mod, 1},
            };
            m = mulMatMat(m, fastPow(mat, num));
        }
        Vec v = {0, A % mod, 1};
        v = mulVecMat(v, m);

        cout << v[0] % mod << endl;
    }
};
