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

class BVotingJudges {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int pivot;
    vector<int> a;
    int n, m, v, p;

    bool check(int i) {
        int val = a[i];
        if (val == pivot) return true;
        if (val + m < pivot) {
            return false;
        }

        int rval = p - 1 + n - i;
        if (rval >= v) {
            return true;
        }
        int vv = v - rval;
        int len = i - p;
        if (vv > len / 2) {
            return false;
        }
        return val + m >= pivot + len / vv;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> n >> m >> v >> p;
        a.resize(n);
        REP(i, n) cin >> a[i];

        sort(a.rbegin(), a.rend());
        pivot = a[p - 1];
        int l = 0;
        int r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l + 1 << endl;
    }
};
