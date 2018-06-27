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

int N, M, F[100005], dp[100005], sum[100005];
int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    REP(i, N) cin >> F[i];

    int l = 0;
    vector<int> L(N + 1, 0);
    map<int, int> cnt;

    FOR(r, 0, N - 1) {
        cnt[F[r]]++;
        while (l + 1 <= r && cnt[F[r]] > 1) {
            cnt[F[l]]--;
            l++;
        }
        L[r + 1] = l;
    }

    dp[0] = 1;
    sum[0] = 1;
    FOR(i, 1, N) {
        if (L[i] > 0) {
            dp[i] = (sum[i - 1] - sum[L[i] - 1] + mod) % mod;
        } else {
            dp[i] = sum[i - 1];
        }
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    cout << dp[N] << endl;

    return 0;
}
