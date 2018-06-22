
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
#define INF (3e15)

using namespace std;

int N, T[100005], A[100005];
int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) cin >> T[i];
    REP(i, N) cin >> A[i];

    if (T[N - 1] != A[0]) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    FOR(i, 1, N - 2) {
        if (T[i] != T[i - 1] && T[i] > A[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (A[i] != A[i + 1] && A[i] > T[i]) {
            cout << 0 << endl;
            return 0;
        }

        if (T[i] != T[i - 1]) continue;
        if (A[i] != A[i + 1]) continue;

        int t = min(T[i], A[i]);
        ans = (ans * t) % mod;
    }
    cout << ans << endl;

    return 0;
}
