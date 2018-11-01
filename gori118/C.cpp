
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

bool search(int x, int a, int b) {
    int num = 0;
    FOR(i, max(1LL, x / 2 - 50), min(x / 2 + 50, x)) {
        int first = i;
        if (first >= a) first++;
        int second = x - i + 1;
        if (second >= b) second++;
        num = max(first * second, num);
        if (first * second < 0) {
            num = INF;
            break;
        }
    }

    int t = a * b;

    return num < t;
}

int solve(int a, int b) {
    int l = 0;
    int r = 3e9 + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (search(mid, a, b)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = solve(a, b);
        cout << ans << endl;
    }

    return 0;
}
