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
        int H, W;
        cin >> H >> W;
        vector<vector<int>> b(H, vector<int>(W));
        vector<vector<int>> w(H, vector<int>(W));
        REP(i, H) {
            REP(j, W) {
                if ((i + j) % 2 == 0) {
                    cin >> b[i][j];
                } else {
                    cin >> w[i][j];
                }
            }
        }

        REP(i, H - 1) {
            REP(j, W) {
                b[i + 1][j] += b[i][j];
                w[i + 1][j] += w[i][j];
            }
        }
        REP(j, W - 1) {
            REP(i, H) {
                b[i][j + 1] += b[i][j];
                w[i][j + 1] += w[i][j];
            }
        }

        int res = 0;
        REP(i, H) {
            REP(j, W) {
                FOR(m, i, H - 1) {
                    FOR(n, j, W - 1) {
                        int bnum = b[m][n];
                        if (i > 0) bnum -= b[i - 1][n];
                        if (j > 0) bnum -= b[m][j - 1];
                        if (i > 0 && j > 0) bnum += b[i - 1][j - 1];

                        int wnum = w[m][n];
                        if (i > 0) wnum -= w[i - 1][n];
                        if (j > 0) wnum -= w[m][j - 1];
                        if (i > 0 && j > 0) wnum += w[i - 1][j - 1];

                        if (bnum == wnum) {
                            res = max(res, (m - i + 1) * (n - j + 1));
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
};
