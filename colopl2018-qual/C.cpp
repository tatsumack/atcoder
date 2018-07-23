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

int A, B;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dfs(int i, set<int> s) {
    int t = A + i;
    if (t > B) return 1;

    bool isDisjoint = true;
    for (auto ts : s) {
        if (gcd(ts, t) != 1) isDisjoint = false;
    }

    int res = 0;
    if (isDisjoint) {
        res += dfs(i + 1, s);
        s.insert(t);
        res += dfs(i + 1, s);
    } else {
        res += dfs(i + 1, s);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    set<int> s;
    int ans = dfs(0, s);
    cout << ans << endl;

    return 0;
}
