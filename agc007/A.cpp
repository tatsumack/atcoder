
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    REP(i, H) {
        REP(j, W) {
            if (A[i][j] != '#') continue;
            bool r = false;
            bool l = false;
            bool d = false;
            bool u = false;
            if (i + 1 < H && A[i + 1][j] == '#') {
                r = true;
            }
            if (j + 1 < W && A[i][j + 1] == '#') {
                d = true;
            }
            if (i - 1 >= 0 && A[i - 1][j] == '#') {
                l = true;
            }
            if (j - 1 >= 0 && A[i][j - 1] == '#') {
                u = true;
            }
            if (i == 0 && j == 0) l = true;
            if (i == H - 1 && j == W - 1) r = true;
            if ((r ^ d) && (l ^ u)) {
                continue;
            }
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;

    return 0;
}
