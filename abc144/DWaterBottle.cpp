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

class DWaterBottle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    double a, b, x;

    double check(double t) {
        t = t * M_PI / 180.0;
        if (a * tan(t) <= b) {
            return a * a * b - a * a * a * tan(t) / 2.0;
        } else {
            return b * b / tan(t) * a / 2.0;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> a >> b >> x;

        double l = 0;
        double r = 90;
        REP(i, 1000000) {
            double m = (r + l) / 2.0;
            double tmp = check(m);
            if (tmp >= x) {
                l = m;
            } else {
                r = m;
            }
        }
        fcout << l << endl;
    }
};
