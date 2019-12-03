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

class FIntervalRunning {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int t1, t2, a1, a2, b1, b2;
        cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
        if (a1 * t1 + a2 * t2 == b1 * t1 + b2 * t2) {
            cout << "infinity" << endl;
            return;
        }
        if (a1 > b1) {
            swap(a1, b1);
            swap(a2, b2);
        }
        if (a1 * t1 + a2 * t2 < b1 * t1 + b2 * t2) {
            cout << 0 << endl;
            return;
        }

        int d1 = b1 * t1 - a1 * t1;
        int d2 = (a1 * t1 + a2 * t2) - (b1 * t1 + b2 * t2);
        int num = d1 / d2;
        int res = 1 + 2 * num;
        if (num > 0 && d1 % d2 == 0) res--;
        cout << res << endl;
    }
};
