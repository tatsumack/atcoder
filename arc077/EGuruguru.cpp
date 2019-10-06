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

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

class EGuruguru {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        REP(i, n) cin >> a[i];

        map<int, int> cnt;
        BIT bit(m + 1);
        FOR(i, 1, n - 1) {
            int d;
            if (a[i] > a[i - 1]) {
                d = a[i] - a[i - 1];
                bit.add(a[i - 1] + 1, 1);
                bit.add(a[i], -1);
            } else {
                d = m - a[i - 1] + a[i];
                bit.add(a[i - 1] + 1, 1);
                bit.add(1, 1);
                bit.add(a[i], -1);
            }
            cnt[a[i]] += d - 1;
        }

        int cur = 0;
        FOR(i, 1, n - 1) {
            if (a[i] > a[i-1]) {
                cur += a[i] - a[i-1];
            } else {
                cur += a[i];
            }
        }

        int res = INF;
        FOR(x, 1, m) {
            cur -= bit.sum(x);
            cur += cnt[x];
            res = min(res, cur);
        }
        cout << res << endl;
    }
};
