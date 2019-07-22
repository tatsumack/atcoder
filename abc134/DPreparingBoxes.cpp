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

std::vector<int> get(int n) {
    std::vector<int> ret;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != 1 && i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

class DPreparingBoxes {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N);
        REP(i, N) cin >> a[i];

        map<int, int> found;
        vector<int> b(N);
        REV(i, N, 1) {
            if (found.count(i)) {
                int d = found[i];
                if (d == a[i - 1]) {
                    b[i - 1] = 0;
                } else {
                    b[i - 1] = 1;
                }
            } else {
                b[i - 1] = a[i - 1];
            }
            auto v = get(i);
            for (int val : v) {
                found[val] += b[i - 1];
                found[val] %= 2;
            }
        }

        vector<int> res;
        REP(i, N) {
            if (b[i] == 0) continue;
            res.push_back(i+1);
        }
        cout << res.size() << endl;
        REP(i, res.size()) cout << res[i] << " ";
    }
};
