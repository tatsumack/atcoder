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

int mod = 1000000007;

int N, M;
int x[100005];
int y[100005];

signed main() {
    cin >> N >> M;
    REP(i, N) cin >> x[i];
    REP(i, M) cin >> y[i];

    int xans = 0;
    REP(i, N) { xans = (xans + (x[i] * i - x[i] * (N - i - 1)) % mod) % mod; }
    int yans = 0;
    REP(i, M) { yans = (yans + (y[i] * i - y[i] * (M - i - 1)) % mod) % mod; }
    int ans = xans * yans % mod;
    cout << ans << endl;

    return 0;
}
