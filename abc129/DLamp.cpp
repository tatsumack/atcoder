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

int N[2005][2005];
int S[2005][2005];
int L[2005][2005];
int R[2005][2005];

class DLamp {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;

        vector<string> s(H);
        REP(i, H) {
            cin >> s[i];
        }

        REP(j, W) N[0][j] = -1;
        REP(i, H) {
            REP(j, W) {
                N[i + 1][j] = N[i][j];
                if (s[i][j] == '#') {
                    N[i + 1][j] = i;
                }
            }
        }

        REP(j, W) S[H - 1][j] = H;
        REV(i, H - 1, 1) {
            REV(j, W - 1, 0) {
                S[i - 1][j] = S[i][j];
                if (s[i][j] == '#') {
                    S[i - 1][j] = i;
                }
            }
        }

        REP(i, H) L[i][0] = -1;
        REP(j, W) {
            REP(i, H) {
                L[i][j + 1] = L[i][j];
                if (s[i][j] == '#') {
                    L[i][j + 1] = j;
                }
            }
        }

        REP(i, H) R[i][W - 1] = W;
        REV(j, W - 1, 1) {
            REV(i, H - 1, 0) {
                R[i][j - 1] = R[i][j];
                if (s[i][j] == '#') {
                    R[i][j - 1] = j;
                }
            }
        }

        int res = -INF;
        REP(i, H) {
            REP(j, W) {
                if (s[i][j] == '#') continue;
                int tmp = (j - L[i][j]) + (R[i][j] - j) + (i - N[i][j]) + (S[i][j] - i);
                tmp -= 3;
                res = max(tmp, res);
            }
        }
        cout << res << endl;

    }
};
