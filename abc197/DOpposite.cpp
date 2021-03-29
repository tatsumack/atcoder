#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

static const double pi = 3.141592653589793;

using namespace std;

class DOpposite {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        double x0, y0, xN2, yN2;
        cin >> x0 >> y0 >> xN2 >> yN2;
        double mx = (x0 + xN2) / 2.0;
        double my = (y0 + yN2) / 2.0;
        x0 -= mx;
        y0 -= my;

        double theta = 2 * pi / N;
        double x1 = x0 * cos(theta) - y0 * sin(theta);
        double y1 = x0 * sin(theta) + y0 * cos(theta);
        fcout << x1 + mx << " " << y1 + my << endl;
    }
};
