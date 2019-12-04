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

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    map<int, int> calc(vector<int>& v) {
        int n = v.size();
        map<int, int> res;
        REP(i, 1 << n) {
            int w = 0;
            REP(j, n) {
                if (i >> j & 1) {
                    w += v[j];
                }
            }
            res[w]++;
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, x;
        cin >> n >> x;
        vector<int> l(n / 2), r(n - l.size());
        REP(i, n) {
            if (i < n / 2) {
                cin >> l[i];
            } else {
                cin >> r[i - l.size()];
            }
        }

        auto lcnt = calc(l);
        auto rcnt = calc(r);

        int res = 0;
        for (auto kv : lcnt) {
            int lx, lnum;
            tie(lx, lnum) = kv;
            res += lnum * rcnt[x - lx];
        }
        cout << res << endl;
    }
};
