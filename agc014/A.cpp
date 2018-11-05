
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

    int A, B, C;
    cin >> A >> B >> C;
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (A == B && B == C) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    while (true) {
        int na = B / 2 + C / 2;
        int nb = A / 2 + C / 2;
        int nc = A / 2 + B / 2;
        A = na;
        B = nb;
        C = nc;
        ans++;

        if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
