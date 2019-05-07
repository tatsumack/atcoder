
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
#include <queue>

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

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<int> A(X), B(Y), C(Z);
    REP(i, X) cin >> A[i];
    REP(i, Y) cin >> B[i];
    REP(i, Z) cin >> C[i];

    priority_queue<int> pq1;
    REP(i, X) {
        REP(j, Y) {
            pq1.push(A[i] + B[j]);
        }
    }

    priority_queue<int> pq2;
    int cnt = 0;
    while (cnt < K && !pq1.empty()) {
        int n = pq1.top();
        pq1.pop();

        REP(i, Z) {
            pq2.push(C[i] + n);
        }

        cnt++;
    }

    cnt = 0;
    while (cnt < K && !pq2.empty()) {
        int n = pq2.top();
        pq2.pop();
        cout << n << endl;

        cnt++;
    }

    return 0;
}
