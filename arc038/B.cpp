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

    vector<vector<int>> memo;
    vector<vector<char>> S;
    int H, W;

    int judge(int i, int j) {
        if (memo[i][j] >= 0) return memo[i][j];

        int res = 0;
        if (i + 1 < H && S[i + 1][j] == '.' && judge(i + 1, j) == 0) res = 1;
        if (j + 1 < W && S[i][j + 1] == '.' && judge(i, j + 1) == 0) res = 1;
        if (i + 1 < H && j + 1 < W && S[i + 1][j + 1] == '.' && judge(i + 1, j + 1) == 0) res = 1;

        return memo[i][j] = res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W;
        memo = vector<vector<int>>(H, vector<int>(W, -1));
        S = vector<vector<char>>(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> S[i][j];

        if (judge(0, 0)) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
};
