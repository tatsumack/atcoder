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

class BTwoContests {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<P> v(N);
        REP(i, N) {
            int l, r;
            cin >> l >> r;
            v[i] = {l, r};
        }
        sort(v.begin(), v.end());

        multiset<int> LL, RL;
        multiset<int> LR, RR;
        multiset<int> L, R;
        int maxv = 0;
        REP(i, N) {
            RL.insert(-v[i].first);
            RR.insert(v[i].second);
            L.insert(-v[i].first);
            R.insert(v[i].second);
        }

        int res = 0;
        REP(i, N - 1) {
            int l = v[i].first;
            int r = v[i].second;
            RL.erase(RL.find(-l));
            RR.erase(RR.find(r));
            LL.insert(-l);
            LR.insert(r);

            int ll = *LL.begin();
            int lr = *LR.begin();
            int rl = *RL.begin();
            int rr = *RR.begin();

            int ls = max(lr + ll + 1, 0LL);
            int rs = max(rr + rl + 1, 0LL);

            res = max(res, ls + rs);
        }

        REP(i, N) {
            int l = v[i].first;
            int r = v[i].second;
            int t1 = max(r - l + 1, 0LL);
            L.erase(L.find(-l));
            R.erase(R.find(r));
            int rr = *R.begin();
            int ll = *L.begin();
            int t2 = max(rr + ll + 1, 0LL);
            res = max(res, t1 + t2);

            L.insert(-l);
            R.insert(r);
        }
        cout << res << endl;
    }
};
