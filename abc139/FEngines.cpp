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
#define fcout cout << fixed << setprecision(48)

using namespace std;

typedef pair<int, int> P;

class FEngines {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<double> x(N), y(N);
        REP(i, N) cin >> x[i] >> y[i];

        vector<pair<double, int>> rad;
        REP(i, N) {
            rad.emplace_back(atan2(x[i], y[i]), i);
            rad.emplace_back(atan2(x[i], y[i]) + 2 * M_PI, i);
        }
        sort(rad.begin(), rad.end());

        double res = 0;
        REP(l, N) {
            FOR(r, l, 2 * N - 1) {
                if (r >= l + N) continue;
                double px = 0;
                double py = 0;
                FOR(i, l, r) {
                    auto kv = rad[i];
                    px += x[kv.second];
                    py += y[kv.second];
                }
                res = max(sqrt(px * px + py * py), res);
            }
        }
        fcout << res << endl;
    }
};
