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

class ETakAndHotels {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> x(N);
        REP(i, N) cin >> x[i];
        x.push_back(x.back() + 1);
        N = x.size();
        int L, Q;
        cin >> L >> Q;

        vector<vector<int>> next(N, vector<int>(51));
        REP(i, N) {
            int to = x[i] + L;
            auto itr = upper_bound(x.begin(), x.end(), to);
            itr--;
            next[i][0] = itr - x.begin();
        }
        REP(j, 50) {
            REP (i, N) {
                int to = next[i][j];
                next[i][j+1] = next[to][j];
            }
        }

        while (Q--) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (a > b) swap(a, b);
            if (a == b) {
                cout << 0 << endl;
                continue;
            }

            int res = 0;
            REV(j, 50, 0) {
                if (next[a][j] < b) {
                    a = next[a][j];
                    res += 1 << j;
                }
            }
            cout << res + 1 << endl;
        }
    }
};
