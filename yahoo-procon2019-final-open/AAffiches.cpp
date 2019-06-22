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

class AAffiches {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        double H, W, A, B;
        cin >> H >> W >> A >> B;

        double dx;
        {
            double k = max((double) 0, 2 * A - H);
            dx = (H - 2 * A) * (A * A - k * k) + 2 * (A * A * A - k * k * k) / 3;
            dx /= (H - A) * (H - A);
        }

        double dy;
        {
            double k = max((double) 0, 2 * B - W);
            dy = (W - 2 * B) * (B * B - k * k) + 2 * (B * B * B - k * k * k) / 3;
            dy /= (W - B) * (W - B);
        }

        fcout << dx * dy << endl;
    }
};
