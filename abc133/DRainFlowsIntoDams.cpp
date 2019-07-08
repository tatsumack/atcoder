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

class DRainFlowsIntoDams {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> A;
    int N;

    bool check(int x) {
        int cur = x;
        REP(i, N) {
            cur = (A[i] - cur / 2) * 2;
            //if (cur < 0) return false;
        }
        if (cur < x) return false;
        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        A.resize(N);
        REP(i, N) cin >> A[i];

        int l = 0;
        int r = INF;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (check(m)) {
                l = m;
            }
            else {
                r = m;
            }
        }
        if (l % 2 == 1) l--;

        int cur = l;
        REP(i, N) {
            cout << cur << " ";
            cur = (A[i] - cur / 2) * 2;
        }
    }
};
