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

class CStrawberryCakes {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, K;
        cin >> H >> W >> K;
        vector<vector<char>> b(H, vector<char>(W));
        REP(i, H) {
            REP(j, W) {
                cin >> b[i][j];
            }
        }

        vector<int> cnt(H);
        REP(i, H) {
            REP(j, W) {
                if (b[i][j] == '#') {
                    cnt[i]++;
                }
            }
        }

        int idx = 0;
        vector<vector<int>> res(H, vector<int>(W));
        REP(i, H) {
            if (cnt[i] == 0) continue;
            bool first = true;
            idx++;
            REP(j, W) {
                if (b[i][j] == '#') {
                    if (first) {
                        first = false;
                    } else {
                        idx++;
                    }
                }
                res[i][j] = idx;
            }
        }

        FOR(i, 1, H - 1) {
            if (cnt[i] != 0) continue;
            int ni = i - 1;
            REP(j, W) {
                res[i][j] = res[ni][j];
            }
        }
        REV(i, H - 2, 0) {
            if (cnt[i] != 0) continue;
            int ni = i + 1;
            REP(j, W) {
                res[i][j] = res[ni][j];
            }
        }

        REP(i, H) {
            REP(j, W) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};
