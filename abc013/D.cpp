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

using namespace std;

int N, M, D, A[200005], T[50][100005];
int MAX_LOG_V = 31;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> D;
    REP(i, M) cin >> A[i], A[i]--;

    REP(i, N) T[0][i] = i;
    REV(i, M - 1, 0) { swap(T[0][A[i]], T[0][A[i] + 1]); }

    REP(k, MAX_LOG_V) {
        REP(i, N) { T[k + 1][i] = T[k][T[k][i]]; }
    }

    vector<int> d;
    REP(i, MAX_LOG_V) {
        if (D & (1 << i)) d.push_back(i);
    }
    REP(i, N) {
        int t = i;
        REP(j, d.size()) { t = T[d[j]][t]; }
        cout << t + 1 << endl;
    }

    return 0;
}
