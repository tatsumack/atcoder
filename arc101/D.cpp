
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

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

bool check(const vector<int>& a, int x) {
    vector<int> sum(a.size() + 1);
    REP(i, a.size()) {
        int val = a[i] >= x ? 1 : -1;
        sum[i + 1] = sum[i] + val;
    }

    BIT bit(sum.size() * 2 + 2);

    int num = 0;
    int offset = sum.size() + 1;
    REP(i, sum.size()) {
        num += bit.sum(sum[i] + offset);
        bit.add(sum[i] + offset, 1);
    }

    int total = (int) a.size() * ((int) a.size() + 1) / 2LL;
    int val = (total + 1) / 2;
    return num >= val;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    REP(i, n) cin >> v[i];

    int l = 1;
    int r = 1e9 + 7;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(v, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;

    return 0;
}
