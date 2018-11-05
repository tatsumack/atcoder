
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
    int N, M;
    cin >> N >> M;
    vector<pair<pair<int, int>, int>> v;
    vector<int> vp(M);
    REP(i, M) {
        int p, y;
        cin >> p >> y;
        vp[i] = p;
        v.push_back({{p, y}, i});
    }
    sort(v.begin(), v.end());

    map<int, int> order;
    int o = 1;
    int prev = v[0].first.first;
    REP(i, v.size()) {
        auto vv = v[i];
        if (vv.first.first != prev) {
            o = 1;
        }
        order[vv.second] = o;
        o++;
        prev = vv.first.first;
    }

    REP(i, M) {
        printf("%06lld", vp[i]);
        printf("%06lld", order[i]);
        cout << endl;
    }

    return 0;
}
