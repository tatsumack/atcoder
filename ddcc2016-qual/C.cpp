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

int N, K, A[200005];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    REP(i, N) cin >> A[i];

    map<int, int> cnt;
    REP(i, N) { cnt[gcd(A[i], K)]++; }

    int ans = 0;
    for (auto& kv1 : cnt) {
        for (auto& kv2 : cnt) {
            if (kv2.first > kv1.first) {
                if ((kv1.first * kv2.first) % K == 0) {
                    ans += kv1.second * kv2.second;
                }
            }
            if (kv1.first == kv2.first) {
                if ((kv1.first * kv2.first) % K == 0) {
                    ans += kv1.second * (kv1.second - 1) / 2;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
