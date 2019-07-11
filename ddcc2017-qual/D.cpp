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

class D {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int H, W, A, B;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W >> A >> B;

        vector<vector<int>> m(H, vector<int>(W));
        int total = 0;
        REP(i, H) {
            REP(j, W) {
                char c;
                cin >> c;
                m[i][j] = c == 'S';
                if (m[i][j]) total++;
            }
        }

        int all = 0;
        int ns = 0;
        int ew = 0;
        REP(i, H / 2) {
            REP(j, W / 2) {
                int b = 0;
                if (m[i][j]) b |= 1 << 0;
                if (m[H - 1 - i][j]) b |= 1 << 1;
                if (m[i][W - 1 - j]) b |= 1 << 2;
                if (m[H - 1 - i][W - 1 - j]) b |= 1 << 3;
                if (b == ((1 << 4) - 1)) {
                    all++;
                } else {
                    if ((b & 3) == 3 || (b & 12) == 12) ns++;
                    if ((b & 5) == 5 || (b & 10) == 10) ew++;
                }
            }
        }

        int res = 0;
        {
            int tmp = 0;
            if (total > all * 4 + ns * 2) tmp += A;
            tmp += A * ns;
            if (total > all * 4) tmp += B;
            tmp += all * (max(A, B) + A + B);
            res = max(res, tmp);
        }
        {
            int tmp = 0;
            if (total > all * 4 + ew * 2) tmp += B;
            tmp += B * ew;
            if (total > all * 4) tmp += A;
            tmp += all * (max(A, B) + A + B);
            res = max(res, tmp);
        }
        cout << res << endl;
    }
};
