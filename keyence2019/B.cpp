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
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string test = "keyence";

    string s;
    cin >> s;

    int l = 0;
    while (l < test.size()) {
        if (s[l] == test[l]) {
            l++;
        } else {
            break;
        }
    }

    if (l == test.size()) {
        cout << "YES" << endl;
        return 0;
    }

    int r = s.size() - 1;
    int tr = test.size() - 1;
    while (r >= 0 && tr >= 0) {
        if (s[r] == test[tr]) {
            r--;
            tr--;
        } else {
            break;
        }
    }

    if (l > tr) {
        cout << "YES" << endl;

    } else {
        cout << "NO" << endl;
    }

    return 0;
}
