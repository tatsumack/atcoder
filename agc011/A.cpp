
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

    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    REP(i, N) cin >> T[i];
    sort(T.begin(), T.end());

    int ans = 0;
    int num = 0;
    int mint = -1;
    REP(i, N) {
        if (mint != -1 && mint + K < T[i]) {
            num = 0;
            mint = -1;
            ans++;
        }
        if (mint == -1) {
            mint = T[i];
        }
        num++;
        if (num == C) {
            num = 0;
            mint = -1;
            ans++;
        }
    }
    if (num > 0) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}
