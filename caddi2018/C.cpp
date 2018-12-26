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
#define INF (LLONG_MAX - 1e5)
#define fcout cout << fixed << setprecision(10)

using namespace std;

int count(vector<int> AA, int d) {
    vector<double> A(AA.size());
    REP(i, AA.size()) A[i] = log2(AA[i]);

    int res = 0;
    REV(i, d - 1, 0) {
        if (i == A.size() - 1 || A[i] > A[i + 1]) {
            continue;
        }
        int diff = A[i+1] - A[i];
        if (diff % 2 == 0) diff++;
        res += diff;
        A[i] += diff;
    }

    FOR(i, d, A.size() - 1) {
        if (i == 0 || A[i] > A[i - 1]) continue;
        int diff = A[i-1] - A[i];
        if (diff % 2 != 0) diff++;
        res += diff;
        A[i] += diff;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    int l = 0;
    int r = N + 1;
    REP(i, 25) {
        int a = (l + l + r) / 3;
        int b = (l + r + r) / 3;
        if (count(A, a) > count(A, b)) {
            l = a;
        } else {
            r = b;
        }
    }
    cout << min({count(A, l), count(A, (l + r) / 2), count(A, r)}) << endl;
    return 0;
}

