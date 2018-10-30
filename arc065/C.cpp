
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

    string s;
    cin >> s;

    int cur = 0;
    bool ok = true;
    REP(i, s.size()) {
        if (cur >= s.size()) break;

        if (s.find("eraser", cur) == cur) {
            cur += 6;
            continue;
        }

        if (s.find("erase", cur) == cur) {
            cur += 5;
            continue;
        }

        if (s.find("dreamer", cur) == cur) {
            if (cur + 7 >= s.size()) continue;
            if (s[cur + 7] == 'd' || s[cur + 7] == 'e') {
                cur += 7;
                continue;
            }
        }

        if (s.find("dream", cur) == cur) {
            cur += 5;
            continue;
        }

        ok = false;
        break;
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
