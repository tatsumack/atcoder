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

class BSortingASegment {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;

        vector<int> p(N);
        REP(i, N) cin >> p[i];
        set<int> s;
        REP(i, K) s.insert(p[i]);

        int res = 1;
        int r = K;
        while (r < N) {
            int l = r - K;
            bool change = false;
            if (p[l] != *s.begin()) change = true;
            if (p[r] < *s.rbegin()) change = true;
            if (change) res++;
            s.erase(p[l]);
            s.insert(p[r]);
            r++;
        }

        int k = 0;
        int cur = 1;
        FOR(i, 1, N - 1) {
            if (p[i] > p[i - 1]) {
                cur++;
            } else {
                if (cur >= K) k++;
                cur = 1;
            }
        }
        if (cur >= K) k++;
        if (k > 1) res -= k - 1;
        cout << res << endl;
    }
};
