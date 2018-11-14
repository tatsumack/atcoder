
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<int> sum(N + 1);
    REP(i, N) {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
    }
    vector<int> b(N + 1);
    FOR(i, 1, N) {
        b[i] = sum[i] - i * K;
    }
    vector<int> sb = b;
    sort(sb.begin(), sb.end());
    sb.erase(unique(sb.begin(), sb.end()), sb.end());
    map<int, int> id;
    REP(i, sb.size()) {
        id[sb[i]] = i;
    }


    // 転倒数
    BIT bit(N + 1);
    int ans = 0;
    REP(i, b.size()) {
        int idx = id[b[i]] + 1;
        ans += bit.sum(idx);
        bit.add(idx, 1);
    }
    cout << ans << endl;

    return 0;
}
