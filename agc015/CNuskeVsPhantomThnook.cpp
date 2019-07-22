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

class CNuskeVsPhantomThnook {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N, M, Q;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> Q;

        vector<string> S(N);
        REP(i, N) {
            cin >> S[i];
        }

        vector<vector<int>> sumv(N + 1, vector<int>(M + 1));
        REP(i, N) {
            REP(j, M) {
                sumv[i + 1][j + 1] = sumv[i][j + 1] + sumv[i + 1][j] - sumv[i][j] + (S[i][j] == '1');
            }
        }
        vector<vector<int>> sumr(N + 1, vector<int>(M + 1));
        REP(i, N) {
            REP(j, M) {
                sumr[i + 1][j + 1] = sumr[i][j + 1] + sumr[i + 1][j] - sumr[i][j];
                if (i >= 1) sumr[i + 1][j + 1] += (S[i][j] == '1' && S[i - 1][j] == '1');
            }
        }
        vector<vector<int>> sumc(N + 1, vector<int>(M + 1));
        REP(i, N) {
            REP(j, M) {
                sumc[i + 1][j + 1] = sumc[i][j + 1] + sumc[i + 1][j] - sumc[i][j];
                if (j >= 1) sumc[i + 1][j + 1] += (S[i][j] == '1' && S[i][j - 1] == '1');
            }
        }

        while (Q--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int v = sumv[x2][y2] - sumv[x1 - 1][y2] - sumv[x2][y1 - 1] + sumv[x1 - 1][y1 - 1];

            int e = sumr[x2][y2] - sumr[x1][y2] - sumr[x2][y1 - 1] + sumr[x1][y1 - 1];
            e += sumc[x2][y2] - sumc[x1 - 1][y2] - sumc[x2][y1] + sumc[x1 - 1][y1];

            cout << v - e << endl;
        }

    }
};
