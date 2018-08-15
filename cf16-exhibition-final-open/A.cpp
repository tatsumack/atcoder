
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

typedef pair<int, int> P;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int mod = 1e9 + 7;
    int N;
    cin >> N;

    vector<P> v;
    REP(i, N) {
        int a;
        cin >> a;
        v.push_back({a, 1});
    }
    REP(i, N) {
        int b;
        cin >> b;
        v.push_back({b, 2});
    }

    sort(v.begin(), v.end());

    int ans = 1;
    stack<int> stack;
    REP(i, 2 * N) {
        P& p = v[i];
        if (stack.empty()) {
            stack.push(p.second);
            continue;
        }

        int t = stack.top();
        if (p.second != t) {
            ans = (ans * stack.size()) % mod;
            stack.pop();
        } else {
            stack.push(p.second);
        }
    }
    cout << ans << endl;

    return 0;
}
