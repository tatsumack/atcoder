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

class CMinCostCycle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i] >> B[i];

        vector<P> v;
        REP(i, N) {
            v.emplace_back(A[i], i);
            v.emplace_back(B[i], i);
        }
        sort(v.begin(), v.end());

        int res = INF;
        {
            int tmp = 0;
            REP(i, N) tmp += A[i];
            res = min(res, tmp);
        }
        {
            int tmp = 0;
            REP(i, N) tmp += B[i];
            res = min(res, tmp);
        }
        {
            int tmp = 0;
            bool ok = false;
            set<int> s;
            REP(i, N) {
                auto kv = v[i];
                if (s.count(kv.second)) ok = true;
                tmp += kv.first;
                s.insert(kv.second);
            }
            if (ok) {
                res = min(res, tmp);
            }
        }
        {
            if (v[N - 1].second == v[N].second) {
                int tmp1, tmp2;
                tmp1 = 0, tmp2 = 0;

                REP(i, N - 1) tmp1 += v[i].first;
                tmp1 += v[N + 1].first;

                REP(i, N - 2) tmp2 += v[i].first;
                tmp2 += v[N - 1].first + v[N].first;

                res = min({res, tmp1, tmp2});
            } else {
                int tmp = 0;
                REP(i, N - 1) tmp += v[i].first;
                tmp += v[N].first;
                res = min(res, tmp);
            }
        }

        cout << res << endl;

    }
};
