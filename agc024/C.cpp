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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
int A[200005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    REP(i, N) { cin >> A[i]; }

    if (A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= N - 2; ++i) {
        if (A[i + 1] - A[i] > 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    int ans = 0;
    for (int i = N - 1; i >= 1; --i) {
        if (A[i] == A[i - 1] + 1) {
            ans++;
        } else {
            ans += A[i];
        }
    }
    cout << ans << endl;

    return 0;
}
