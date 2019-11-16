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

class B {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N;
    vector<int> x, y, c;

    bool check(double t) {
        REP(i, N) {
            double dx = t / c[i];
            double dy = t / c[i];
            FOR(j, i + 1, N - 1) {
                double dx2 = t / c[j];
                double dy2 = t / c[j];

                if (dx + dx2 < abs(x[i] - x[j])) return false;
                if (dy + dy2 < abs(y[i] - y[j])) return false;
            }
        }
        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        x.resize(N);
        y.resize(N);
        c.resize(N);
        REP(i, N) {
            cin >> x[i] >> y[i] >> c[i];
        }

        double ng = 0;
        double ok = 10000000000;
        REP(i, 100) {
            double mid = (ok + ng) / 2;
            if (check(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        fcout << ok << endl;
    }
};
