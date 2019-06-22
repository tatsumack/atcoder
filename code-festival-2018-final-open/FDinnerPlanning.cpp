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

class FDinnerPlanning {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;

        int res = 0;
        multiset<int> s, t;

        REP(i, K) t.insert(INF);
        while (N--) {
            int T, A;
            cin >> T >> A;
            res += A;
            if (T == 0) {
                t.insert(A);
                if (s.empty()) {
                    auto itr = t.begin();
                    res -= *itr;
                    t.erase(itr);
                } else {
                    auto itr = s.end();
                    itr--;
                    s.erase(itr);
                }
            } else {
                s.insert(A);
                if (t.empty()) {
                    auto itr = s.begin();
                    res -= *itr;
                    s.erase(itr);
                } else {
                    auto itr = t.end();
                    itr--;
                    t.erase(itr);
                }
            }
        }
        cout << res << endl;
    }
};
