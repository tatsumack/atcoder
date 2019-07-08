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

class BGoodDistance {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    bool check(int x) {
        for (int i = 1; i * i <= x; i++) {
            if (i * i == x) return true;
        }

        return false;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, D;
        cin >> N >> D;
        vector<vector<int>> X(N, vector<int>(D));
        REP(i, N) {
            REP(j, D) {
                cin >> X[i][j];
            }
        }

        int res = 0;
        REP(i, N) {
            FOR(j, i + 1, N - 1) {
                int d = 0;
                REP(k, D) {
                    d += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
                }
                if (check(d)) {
                    res++;
                }
            }
        }
        cout << res << endl;

    }
};
