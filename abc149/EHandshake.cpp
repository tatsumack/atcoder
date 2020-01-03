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

class EHandshake {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> a;

    int n, m;

    bool check(int v) {
        int num = 0;
        REP(i, n) {
            int o = v - a[i];
            int idx = lower_bound(a.begin(), a.end(), o) - a.begin();
            num += n - idx;
        }
        return num >= m;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> n >> m;
        a.resize(n);
        REP(i, n) cin >> a[i];
        sort(a.begin(), a.end());

        int l = 0;
        int r = INF;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        vector<int> sum(n + 1);
        REP(i, n) sum[i + 1] = sum[i] + a[i];

        int res = 0;
        int num = 0;
        REP(i, n) {
            int o = r - a[i];
            int idx = lower_bound(a.begin(), a.end(), o) - a.begin();
            res += a[i] * (n - idx) + (sum[n] - sum[idx]);
            num += (n - idx);
        }
        if (m > num) {
            res += l * (m - num);
        }
        cout << res << endl;
    }
};
