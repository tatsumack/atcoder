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

class B {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, k;
        cin >> n >> k;

        vector<int> x(n);
        REP(i, n) cin >> x[i];

        priority_queue<P> pq;

        vector<int> res;
        REP(i, n) {
            if (pq.size() == k) {
                int age, pos;
                tie(age, pos) = pq.top();
                if (x[i] < age) {
                    pq.pop();
                    pq.push({x[i], i + 1});
                }
                res.push_back(pq.top().second);
            } else {
                pq.push({x[i], i + 1});
                if (pq.size() == k) {
                    res.push_back(pq.top().second);
                }
            }
        }

        REP(i, res.size()) {
            cout << res[i] << endl;
        }

    }
};
