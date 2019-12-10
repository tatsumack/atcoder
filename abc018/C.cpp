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
        int r, c, k;
        cin >> r >> c >> k;

        vector<string> s(r);
        REP(i, r) {
            cin >> s[i];
        }

        vector<vector<int>> u(r, vector<int>(c, 0));
        vector<vector<int>> d(r, vector<int>(c, 0));
        REP(i, r) {
            REP(j, c) {
                if (s[i][j] == 'o') {
                    u[i][j] = 1;
                    d[i][j] = 1;
                }
            }
        }
        FOR(i, 1, r - 1) {
            REP(j, c) {
                if (u[i][j] == 0) continue;
                u[i][j] += u[i-1][j];
            }
        }

        REV(i, r-2, 0) {
            REP(j, c) {
                if (d[i][j] == 0) continue;
                d[i][j] += d[i+1][j];
            }
        }

        int res = 0;
        REP(i, r) {
            REP(j, c) {
                int cur = k;
                int diff = 0;

                bool ok = true;
                while (cur > 0) {
                    int ll = j - diff;
                    int rr = j + diff;
                    if (ll < 0 || rr >= c) {
                        ok = false;
                        break;
                    }
                    if (u[i][ll] < cur) ok = false;
                    if (d[i][ll] < cur) ok = false;
                    if (u[i][rr] < cur) ok = false;
                    if (d[i][rr] < cur) ok = false;
                    cur--;
                    diff++;
                }
                if (ok) res++;
            }
        }
        cout << res << endl;
    }
};
