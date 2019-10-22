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

class DTriangles {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> l(n);

        REP(i, n) {
            cin >> l[i];
        }
        sort(l.begin(), l.end());

        int res = 0;
        REP(i, n - 2) {
            FOR(j, i + 1, n - 2) {
                int x = l[i] - l[j];
                int v = l[i] + l[j];
                int pos1 = upper_bound(l.begin(), l.end(), x) - l.begin();
                int pos2 = lower_bound(l.begin(), l.end(), v) - l.begin();
                int num = pos2 - max(pos1, j + 1);
                if (num < 0) continue;
                res += num;
            }
        }
        cout << res << endl;
    }
};
