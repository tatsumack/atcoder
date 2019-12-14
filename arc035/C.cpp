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

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> d(n, vector<int>(n, INF));
        REP(i, n) d[i][i] = 0;
        REP(i, m) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            d[a][b] = c;
            d[b][a] = c;
        }


        REP(k, n) {
            REP(i, n) {
                REP(j, n) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        int k;
        cin >> k;
        REP(i, k) {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--;

            REP(i, n) {
                REP(j, n) {
                    d[i][j] = min(d[i][j], d[i][x] + z + d[y][j]);
                    d[i][j] = min(d[i][j], d[i][y] + z + d[x][j]);
                }
            }

            int s = 0;
            REP(i, n) {
                FOR(j, i + 1, n - 1) {
                    s += d[i][j];
                }
            }
            cout << s << endl;
        }

    }
};
