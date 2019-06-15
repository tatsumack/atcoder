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

class BPickingUp {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> x(N), y(N);
        REP(i, N) cin >> x[i] >> y[i];

        if (N == 1) {
            cout << 1 << endl;
            return;
        }

        vector<int> p, q;
        REP(i, N) {
            FOR(j, i+1, N-1) {
                p.push_back(x[j] - x[i]);
                q.push_back(y[j] - y[i]);
            }
        }

        int res = INF;
        REP(i, p.size()) {

            int tmp = 0;
            map<pair<int, int>, bool> used;
            REP(j, N) {
                used[{x[j], y[j]}] = false;
            }
            REP(j, N) {
                if (used[{x[j], y[j]}]) continue;

                tmp++;
                int cur_x = x[j];
                int cur_y = y[j];
                used[{cur_x, cur_y}] = true;
                while (used.count({cur_x - p[i], cur_y - q[i]}) > 0)  {
                    cur_x -= p[i];
                    cur_y -= q[i];
                    used[{cur_x, cur_y}] = true;
                }
                while (used.count({cur_x + p[i], cur_y + q[i]}) > 0)  {
                    cur_x += p[i];
                    cur_y += q[i];
                    used[{cur_x, cur_y}] = true;
                }
            }
            res = min(res, tmp);
        }
        cout << res << endl;

    }
};
