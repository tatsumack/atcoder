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

class CRectangle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, h, w;
        cin >> H >> W >> h >> w;

        if (H % h == 0 && W % w == 0) {
            cout << "No" << endl;
            return;
        }

        cout << "Yes" << endl;
        vector<vector<int>> ans(H, vector<int>(W));
        if (H % h != 0) {
            REP(i, H) {
                REP(j, W) {
                    ans[i][j] = i % h == 0 ? h * 1000 - 1001 : -1000;
                }
            }
        } else {
            REP(i, H) {
                REP(j, W) {
                    ans[i][j] = j % w == 0 ? w * 1000 - 1001 : -1000;
                }
            }
        }
        REP(i, H) {
            REP(j, W) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};
