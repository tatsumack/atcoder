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

class EConnected {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int R, C, N;

    bool onLine(int x, int y) {
        return x == 0 || x == R || y == 0 || y == C;
    }

    int convert(int x, int y) {
        if (x == 0) {
            return y;
        }
        if (x == R) {
            return C - y + C + R;
        }
        if (y == 0) {
            return R - x + 2 * C + R;
        }
        if (y == C) {
            return x + C;
        }
        return 0;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> R >> C >> N;
        set<P> s;
        REP(i, N) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if (onLine(x1, y1) && onLine(x2, y2)) {
                s.insert({convert(x1, y1), i});
                s.insert({convert(x2, y2), i});
            }
        }

        stack<int> st;
        for (auto kv : s) {
            if (!st.empty() && kv.second == st.top()) {
                st.pop();
                continue;
            }
            st.push(kv.second);
        }

        cout << (st.empty() ? "YES" : "NO") << endl;
    }
};
