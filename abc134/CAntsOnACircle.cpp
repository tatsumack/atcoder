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

class CAntsOnACircle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, L, T;
        cin >> N >> L >> T;
        vector<int> X(N), W(N);

        vector<int> cond;
        REP(i, N) {
            cin >> X[i] >> W[i];

            if (W[i] != W[0]) {
                cond.push_back(X[i]);
            }
        }

        int t = T % L;
        int n = T / L;
        int cnt = 0;
        REP(i, N) {
            if (W[i] == 1) {
                cnt -= n + (t >= L - X[i]);
                //cnt -= (T - (L - X[i]) + L) / L;
            } else {
                cnt += n + (t >= (X[i] + 1) % L);
                //cnt += (T - (X[i] + 1) + L) / L;
            }
        }
        cnt = ((cnt % N) + N) % N;

        vector<int> v;
        REP(i, N) {
            int x = X[i];
            int w = W[i];

            if (w == 1) {
                x += t;
                x %= L;
            } else {
                x -= t;
                if (x < 0) x += L;
            }
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        vector<int> ans(N);
        REP(i, N) ans[(i + cnt) % N] = v[i];

        REP(i, N) cout << ans[i] << endl;
    }
};
