
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


int mod = 1e9 + 7;
int sum[100005];
int dp[100005][100005];

int f(int l, int r, const vector<int>& A) {
    if (dp[l][r] > 0) return dp[l][r];

    if (r <= l) {
        return 0;
    }

    int res = 0;
    FOR(m, l, r - 1) {
        int tmp = (sum[r] - sum[l]) % mod;
        tmp = (tmp + f(l, m, A)) % mod;
        tmp = (tmp + f(m + 1, r, A)) % mod;
        if (l < m && m < r-1) {
            tmp = (tmp*2) % mod;
        }
        res = (res + tmp) % mod;
    }

    return dp[l][r] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
        sum[i + 1] = (sum[i] + A[i]) % mod;
    }

    int ans = f(0, N, A);
    cout << ans << endl;

    return 0;
}
