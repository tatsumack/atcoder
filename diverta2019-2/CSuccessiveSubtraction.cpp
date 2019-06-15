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

class CSuccessiveSubtraction {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N);
        REP(i, N) cin >> a[i];

        vector<int> plus, minus;
        REP(i, N) {
            if (a[i] > 0) {
                plus.push_back(a[i]);
            }
            else {
                minus.push_back(a[i]);
            }
        }
        sort(plus.begin(), plus.end());
        sort(minus.begin(), minus.end(), greater<int>());

        vector<pair<int, int>> op;
        if (minus.empty()) {
            int target = plus[0];
            FOR(i, 1, plus.size() - 2) {
                op.push_back({target, plus[i]});
                target -= plus[i];
            }
            op.push_back({plus.back(), target});
            cout << plus.back() - target << endl;
        }
        else if (plus.empty()) {
            int target = minus[0];
            FOR(i, 1, minus.size() - 2) {
                op.push_back({target, minus[i]});
                target -= minus[i];
            }
            op.push_back({target, minus.back()});
            cout << target - minus.back() << endl;
        }
        else {
            int target1 = plus[0];
            FOR(i, 1, minus.size() - 1) {
                op.push_back({target1, minus[i]});
                target1 -= minus[i];
            }
            int target2 = minus[0];
            FOR(i, 1, plus.size() - 1) {
                op.push_back({target2, plus[i]});
                target2 -= plus[i];
            }
            op.push_back({target1, target2});
            cout << target1 - target2 << endl;
        }
        REP(i, op.size()) {
            cout << op[i].first << " " << op[i].second << endl;
        }
    }
};
