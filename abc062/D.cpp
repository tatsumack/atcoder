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
#include <queue>
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
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
int A[3 * 100005];

int sum1[100005];
int sum2[100005];

signed main() {
    cin >> N;

    REP(i, N * 3) { cin >> A[i]; }

    priority_queue<int, vector<int>, greater<int> > fque;
    int fsum = 0;
    REP(i, N) {
        fque.push(A[i]);
        fsum += A[i];
    }
    sum1[0] = fsum;

    priority_queue<int> sque;
    int ssum = 0;
    FOR(i, 2 * N, 3 * N) {
        sque.push(A[i]);
        ssum += A[i];
    }
    sum2[N] = ssum;

    int ans = -INF;
    for (int k = N; k <= 2 * N - 1; ++k) {
        fsum += A[k];
        fque.push(A[k]);
        int r = fque.top();
        fque.pop();
        fsum -= r;
        sum1[k - (N - 1)] = fsum;
    }
    for (int k = 2 * N - 1; k >= N; --k) {
        ssum += A[k];
        sque.push(A[k]);
        int r = sque.top();
        sque.pop();
        ssum -= r;
        sum2[k - N] = ssum;
    }
    REP(i, N + 1)
    ans = max(ans, sum1[i] - sum2[i]);
    cout << ans << endl;

    return 0;
}
