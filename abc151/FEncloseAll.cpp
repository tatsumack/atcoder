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
#include <complex>
#include <algorithm>

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

using ld = double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P& a, const P& b) { return a.real()*b.imag() - a.imag()*b.real(); }
ld dot(const P& a, const P& b) { return a.real()*b.real() + a.imag()*b.imag(); }

using C = pair<ld, P>;
#define rad first
#define pnt second

C smallest_enclosing_disc(vector<P> ps){
    auto c3 = [](const P &a, const P &b, const P &c){
        ld A = norm(b - c);
        ld B = norm(c - a);
        ld C = norm(a - b);
        ld S = abs(cross(b - a, c - a));
        P p = (A*(B+C-A)*a + B*(C+A-B)*b + C*(A+B-C)*c) / (4*S*S);
        ld r = abs(p - a);
        return make_pair(r, p);
    };

    auto c2 = [](const P &a, const P &b){
        P c = (a + b) / (ld)2;
        ld r = abs(a - c);
        return make_pair(r, c);
    };

    auto in_circle = [](const P &a, const C &c){
        return norm(a - c.pnt) <= c.rad*c.rad + eps;
    };

    int n = ps.size();
    random_shuffle(ps.begin(), ps.end());
    C c = c2(ps[0], ps[1]);
    for(int i = 2; i < n; ++i){
        if(!in_circle(ps[i], c)){
            c = c2(ps[0], ps[i]);
            for(int j = 1; j < i; ++j){
                if(!in_circle(ps[j], c)){
                    c = c2(ps[j], ps[i]);
                    for(int k = 0; k < j; ++k){
                        if(!in_circle(ps[k], c)){
                            c = c3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}


class FEncloseAll {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        G g(N);
        REP(i, N) {
            double x, y;
            cin >> x >> y;
            g[i] = P(x, y);
        }
        fcout << smallest_enclosing_disc(g).rad << endl;
    }
};
