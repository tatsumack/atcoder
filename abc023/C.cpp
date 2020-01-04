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

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int R, C, K, N;
        cin >> R >> C >> K >> N;
        vector<int> r(N), c(N);
        REP(i, N) cin >> r[i] >> c[i];

        map<int, int> rnum, cnum, rval, cval;
        set<int> rset, cset;
        REP(i, N) {
            rnum[r[i]]++;
            cnum[c[i]]++;
        }

        for (auto kv : rnum) {
            rval[kv.second]++;
        }
        rval[0] = R - rnum.size();
        for (auto kv : cnum) {
            cval[kv.second]++;
        }
        cval[0] = C - cnum.size();

        int res = 0;
        for (auto kv : rval) {
            int rv, num;
            tie(rv, num) = kv;
            if (rv > K) continue;
            int cv = K - rv;
            res += rval[rv] * cval[cv];
        }

        REP(i, N) {
            if (rnum[r[i]] + cnum[c[i]] == K) res--;
            if (rnum[r[i]] + cnum[c[i]] == K + 1) res++;
        }
        cout << res << endl;
    }
};
