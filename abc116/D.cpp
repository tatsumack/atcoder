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
#include <queue>

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

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> v(N);
    REP(i, N) {
        int t, d;
        cin >> t >> d;
        v[i] = {d, t};
    }
    sort(v.begin(), v.end(), greater<P>());


    priority_queue<P, vector<P>, greater<P>> big;
    priority_queue<P> small;
    map<int, int> kind;

    int ans = 0;
    REP(i, N) {
        if (i < K) {
            big.push(v[i]);
            kind[v[i].second]++;
            ans += v[i].first;
        } else {
            small.push(v[i]);
        }
    }
    int size = kind.size();
    ans += size * size;

    map<int, int> kans;
    kans[size] = ans;
    while (!small.empty() && !big.empty()) {
        auto kvb = big.top();
        if (kind[kvb.second] == 1) {
            big.pop();
            continue;
        }
        auto kvs = small.top();
        if (kind[kvs.second] > 0) {
            small.pop();
            continue;
        }

        int tmp = kans[size] - kvb.first + kvs.first + (size + 1) * (size + 1) - size * size;
        ans = max(ans, tmp);

        size++;
        kans[size] = tmp;
        big.pop();
        small.pop();
        kind[kvs.second]++;
    }

    cout << ans << endl;

    return 0;
}
