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

int N, S;

int f(int b, int n) { return n < b ? n : f(b, n / b) + n % b; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    if (N < S) {
        cout << -1 << endl;
        return 0;
    }
    if (N == S) {
        cout << N + 1 << endl;
        return 0;
    }

    for (int i = 2; i * i <= N; ++i) {
        if (f(i, N) == S) {
            cout << i << endl;
            return 0;
        }
    }

    int ans = INF;
    for (int p = 1; p * p < N; ++p) {
        if ((N - S + p) % p != 0) continue;
        int b = (N - S + p) / p;
        if (b == 1) continue;
        if (f(b, N) == S) {
            ans = min(ans, b);
        }
    }
    if (ans != INF) {
        cout << ans << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
