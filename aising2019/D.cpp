
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), X(Q), sum(N + 1), sum2(N + 1);
    REP(i, N) cin >> A[i];
    REP(i, Q) cin >> X[i];

    sum2[0] = A[0];
    sum2[1] = A[1];
    REP(i, N) {
        sum[i + 1] = sum[i] + A[i];
        if (i - 2 >= 0) {
            sum2[i] = sum2[i - 2] + A[i];
        }
    }

    REP(q, Q) {
        int x = X[q];
        int ok = N - 1;
        int ng = 0;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;

            int upper = N - 1 - mid + 1;
            int lower = mid - static_cast<int>(lower_bound(A.begin(), A.end(), x - (A[mid] - x)) - A.begin()) + 1;
            if (upper <= lower) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        int res = sum[N] - sum[ok];
        int next = N - 1 - (N - ok) * 2;
        if (next >= 0) res += sum2[next];
        cout << res << endl;
    }

    return 0;
}
