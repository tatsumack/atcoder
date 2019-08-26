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

class DClassified {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> ans;

    void calc(int l, int r, int x) {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        FOR(i, l, m - 1) {
            FOR(j, m, r - 1) {
                ans[i][j] = x;
            }
        }
        calc(l, m, x + 1);
        calc(m, r, x + 1);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        ans = vector<vector<int>>(N, vector<int>(N));
        calc(0, N, 1);
        REP(i, N) {
            FOR(j, i + 1, N - 1) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};
