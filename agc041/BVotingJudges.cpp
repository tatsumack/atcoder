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

class BVotingJudges {
public:
    int N, M, V, P;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> V >> P;

        vector<int> A(N);
        REP(i, N) cin >> A[i];

        sort(A.begin(), A.end());
        int b = A[N - 1 - (P - 1)];

        vector<int> sum(N + 1);
        REP(i, N) sum[i + 1] = sum[i] + A[i];

        int res = 0;
        REP(i, N) {
            int a = A[i];
            if (a >= b) {
                res++;
                continue;
            }
            if (a + M < b) {
                continue;
            }

            int rem = V - (P - 1 + i + 1);
            rem *= M;
            if (rem <= 0) {
                res++;
                continue;
            }

            int from = i + 1;
            int to = N - 1 - (P - 1);
            int num = to - from + 1;
            int val = (A[i] + M) * num - (sum[to + 1] - sum[from]);
            if (rem <= val) {
                res++;
            }
        }
        cout << res << endl;
    }
};
