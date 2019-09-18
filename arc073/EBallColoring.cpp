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

class EBallColoring {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<P> v(N);
        int minVal = INF;
        int maxVal = -INF;
        REP(i, N) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            v[i] = {x, y};
            if (x < minVal || y < minVal) {
                minVal = min(x, y);
            }
            if (x > maxVal || y > maxVal) {
                maxVal = max(x, y);
            }
        }

        int res = INF;

        // Rmax最大、 Bminが最小
        {
            set<int> R, B;
            REP(i, N) {
                int x, y;
                tie(x, y) = v[i];
                if (x > y) swap(x, y);
                R.insert(y);
                B.insert(x);
            }
            res = (*R.rbegin() - *R.begin()) * (*B.rbegin() - *B.begin());
        }

        // Rmax最大, Rmin最小
        {
            multiset<int> B;
            REP(i, N) {
                int x, y;
                tie(x, y) = v[i];
                if (x > y) swap(x, y);
                B.insert(x);
            }
            res = min(res, (maxVal - minVal) * (*B.rbegin() - *B.begin()));

            sort(v.begin(), v.end());
            REP(i, v.size()) {
                B.erase(B.find(v[i].first));
                B.insert(v[i].second);
                res = min(res, (maxVal - minVal) * (*B.rbegin() - *B.begin()));
            }
        }
        cout << res << endl;
    }
};
