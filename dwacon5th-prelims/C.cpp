
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    string S;
    cin >> N >> S >> Q;

    vector<int> d(N + 1);
    REV(i, N - 1, 0) {
        int t = S[i] == 'D' ? 1 : 0;
        d[i] = d[i + 1] + t;
    }
    vector<int> c(N + 1);
    c[0] = S[0] == 'C' ? 1 : 0;
    FOR(i, 1, N - 1) {
        int t = S[i] == 'C' ? 1 : 0;
        c[i] = c[i - 1] + t;
    }

    while (Q--) {
        int k;
        cin >> k;
        FOR(l, 1, k-2) {

        }
    }
    return 0;
}
