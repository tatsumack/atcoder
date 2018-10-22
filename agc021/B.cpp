
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
#include <complex>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define fcout cout << fixed << setprecision(10)

using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = 2 * acos(0.0);

typedef complex<double> P;

namespace std {
    bool operator<(const P& a, const P& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

double cross(const P& a, const P& b) {
    return imag(conj(a) * b);
}

double dot(const P& a, const P& b) {
    return real(conj(a) * b);
}

struct L : public vector<P> {
    L(const P& a, const P& b) {
        push_back(a);
        push_back(b);
    }
};

typedef vector<P> G;

struct C {
    P p;
    double r;

    C(const P& p, double r) : p(p), r(r) {}
};

int ccw(P a, P b, P c) {
    b -= a;
    c -= a;
    if (cross(b, c) > 0) return 0;       // counter clockwise
    if (cross(b, c) < 0) return 1;       // clockwise
    if (dot(b, c) < 0) return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}

vector<P> convex_hull(vector<P> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<P> ch(2 * n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
        while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
        while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
    ch.resize(k - 1);
    return ch;
}

double calc_angle(const P& a, const P& b, const P& c) { // argument for A->B->C
    P ab = a - b;
    P cb = c - b;

    double arg = dot(ab, cb) / abs(ab) / abs(cb);
    arg = min(arg, 1.0);
    arg = max(arg, -1.0);

    return acos(arg);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    if (N == 2) {
        cout << 0.5 << endl;
        cout << 0.5 << endl;
        return 0;
    }

    vector<P> ps(N);
    REP(i, N) {
        double x, y;
        cin >> x >> y;
        ps[i] = P(x, y);
    }

    vector<P> cvx = convex_hull(ps);
    vector<double> ans(N);
    REP(i, cvx.size()) {
        int a = i;
        int b = (i + 1) % cvx.size();
        int c = (i + 2) % cvx.size();

        int id = -1;
        REP(j, N) {
            if (abs(ps[j] - cvx[b]) < EPS) {
                id = j;
                break;
            }
        }
        if (id == -1) continue;
        ans[id] = (PI - calc_angle(cvx[a], cvx[b], cvx[c])) / (2.0 * PI);
    }

    REP(i, N) {
        fcout << ans[i] << endl;
    }

    return 0;
}
