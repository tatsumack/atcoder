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

class FMinimumBoundingBox {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N;
    vector<double> R, L, U, D, X, Y;

    vector<double> xtimes() {
        vector<double> res;
        REP(i, 2) {
            double t;
            if (!X.empty() && !R.empty()) {
                t = i == 0 ? X.front() - R.front() : X.back() - R.back();
                if (t > 0) res.push_back(t);
            }
            if (!X.empty() && !L.empty()) {
                t = i == 0 ? L.front() - X.front() : L.back() - X.back();
                if (t > 0) res.push_back(t);
            }
            if (!R.empty() && !L.empty()) {
                t = i == 0 ? L.front() - R.front() : L.back() - R.back();
                if (t > 0) res.push_back(t / 2.0f);
            }
        }
        return res;
    }

    vector<double> ytimes() {
        vector<double> res;
        REP(i, 2) {
            double t;
            if (!Y.empty() && !U.empty()) {
                t = i == 0 ? Y.front() - U.front() : Y.back() - U.back();
                if (t > 0) res.push_back(t);
            }
            if (!Y.empty() && !D.empty()) {
                t = i == 0 ? D.front() - Y.front() : D.back() - Y.back();
                if (t > 0) res.push_back(t);
            }
            if (!U.empty() && !D.empty()) {
                t = i == 0 ? D.front() - U.front() : D.back() - U.back();
                if (t > 0) res.push_back(t / 2.0f);
            }
        }
        return res;

    }

    double calc(double t) {
        vector<double> xs, ys;
        if (!L.empty()) {
            xs.push_back(L.front() - t);
            xs.push_back(L.back() - t);
        }
        if (!R.empty()) {
            xs.push_back(R.front() + t);
            xs.push_back(R.back() + t);
        }
        if (!X.empty()) {
            xs.push_back(X.front());
            xs.push_back(X.back());
        }
        if (!U.empty()) {
            ys.push_back(U.front() + t);
            ys.push_back(U.back() + t);
        }
        if (!D.empty()) {
            ys.push_back(D.front() - t);
            ys.push_back(D.back() - t);
        }
        if (!Y.empty()) {
            ys.push_back(Y.front());
            ys.push_back(Y.back());
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        return (xs.back() - xs.front()) * (ys.back() - ys.front());
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        REP(i, N) {
            double x, y;
            char d;
            cin >> x >> y >> d;
            if (d == 'R') R.push_back(x), Y.push_back(y);
            if (d == 'L') L.push_back(x), Y.push_back(y);
            if (d == 'U') X.push_back(x), U.push_back(y);
            if (d == 'D') X.push_back(x), D.push_back(y);
        }
        sort(R.begin(), R.end());
        sort(L.begin(), L.end());
        sort(U.begin(), U.end());
        sort(D.begin(), D.end());
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        vector<double> times;
        times.push_back(0);
        auto xs = xtimes();
        auto ys = ytimes();
        times.insert(times.end(), xs.begin(), xs.end());
        times.insert(times.end(), ys.begin(), ys.end());

        double res = 1e18;
        for (auto t: times) {
            res = min(res, calc(t));
        }
        fcout << res << endl;
    }
};
