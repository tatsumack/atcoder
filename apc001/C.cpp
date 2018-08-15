
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

int N;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    string lval;
    int l = 0;
    cout << l << endl;
    cin >> lval;
    if (lval == "Vacant") return 0;

    int r = N - 1;
    cout << r << endl;
    string rval;
    cin >> rval;
    if (rval == "Vacant") return 0;

    while (r > l) {
        int m = (r + l) / 2 / 2 * 2;
        if (m == l) m++;
        cout << m << endl;

        string ans;
        cin >> ans;
        if (ans == "Vacant") return 0;

        if (ans == lval) {
            l = m;
        } else {
            r = m;
        }
    }

    return 0;
}
