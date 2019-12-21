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

class nikkei2019_2_qual_e {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, k;
        cin >> n >> k;
        vector<int> v1(n), v2(n);

        int idx = 0;
        REP(i, n) {
            if (idx >= n) idx = 1;
            v1[idx] = k + i;
            idx += 2;
        }

        idx = 1;
        REP(i, n) {
            if (idx >= n) idx = 0;
            v2[idx] = k + i + n;
            idx += 2;
        }

        REP(i, n) {
            if (v1[i] + v2[i] > k + 2 * n + i) {
                cout << -1 << endl;
                return;
            }
        }
        REP(i, n) {
            cout << v1[i] << " " << v2[i] << " " << k + 2 * n + i << endl;
        }
    }
};
