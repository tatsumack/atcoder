
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

    int L;
    cin >> L;

    vector<int> two;
    int t = 1;
    REP(i, 30) {
        two.push_back(t);
        t *= 2;
    }

    int n = 0;
    int bnum = 0;
    int tmp = L;
    while (tmp > 0) {
        if ((tmp & 1) == 1) bnum++;
        tmp /= 2;
        n++;
    }

    int m = (n - 1) * 2 + bnum-1;

    cout << n << " " << m << endl;

    FOR(i, 1, n - 1) {
        cout << i << " " << i + 1 << " " << 0 << endl;
    }

    FOR(i, 1, n - 1) {
        cout << i << " " << i + 1 << " " << two[n - 2 - (i - 1)] << endl;
    }

    tmp = L;
    int mask = 0;
    int cnt = 0;
    while (tmp > 0 && cnt < n-1)
    {
        if ((tmp & 1) == 1) {
            mask = mask | (1 << cnt);
            int c = L - mask;
            cout << 1 << " " << n - cnt << " " << c << endl;
        }
        tmp /= 2;
        cnt++;
    }

    return 0;
}
