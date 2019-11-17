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

class CAverageLength {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<double> x, y;
    set<double> s;
    int N;

    double dfs(int v, int d, double cur) {
        if (d == N - 1) {
            return cur;
        }

        s.insert(v);
        double res = 0;
        REP(i, N) {
            if (s.count(i)) continue;
            double tmp = sqrt((x[v] - x[i]) * (x[v] - x[i]) + (y[v] - y[i]) * (y[v] - y[i]));
            res += dfs(i, d + 1, cur + tmp);
        }
        s.erase(v);
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        x = vector<double>(N);
        y = vector<double>(N);
        REP(i, N) cin >> x[i] >> y[i];

        double sum = 0;
        REP(i, N) {
            sum += dfs(i, 0, 0);
        }

        int m = 1;
        FOR(i, 1, N) m *= i;
        fcout << sum / (double) m << endl;
    }
};
