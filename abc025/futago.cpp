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

class futago {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int b[2][3];
    int c[3][2];
    int g[3][3];
    int total;

    int calc() {
        int res = 0;
        REP(i, 2) {
            REP(j, 3) {
                if (g[i][j] == g[i + 1][j]) res += b[i][j];
            }
        }
        REP(i, 3) {
            REP(j, 2) {
                if (g[i][j] == g[i][j + 1]) res += c[i][j];
            }
        }

        return res - (total - res);
    }

    int dfs(int turn) {
        if (turn == 9) {
            return calc();
        }

        int res = turn % 2 == 0 ? -INF : INF;
        REP(i, 3) {
            REP(j, 3) {
                if (g[i][j] != -1) continue;
                g[i][j] = turn % 2;

                if (turn % 2 == 0) {
                    res = max(res, dfs(turn + 1));
                } else {
                    res = min(res, dfs(turn + 1));
                }
                g[i][j] = -1;
            }
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        total = 0;
        REP(i, 2) REP(j, 3) cin >> b[i][j], total += b[i][j];
        REP(i, 3) REP(j, 2) cin >> c[i][j], total += c[i][j];

        REP(i, 3) REP(j, 3) g[i][j] = -1;

        int res = dfs(0);
        int score = (total + res) / 2;
        cout << score << endl;
        cout << total - score << endl;
    }
};
