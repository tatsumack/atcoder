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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, W;

signed main() {
    cin >> N >> W;

    vector<int> w1, w2, w3, w4;
    int w, v;
    cin >> w >> v;
    w1.push_back(v);
    REP(i, N - 1) {
        int tw, tv;
        cin >> tw >> tv;
        if (tw == w) w1.push_back(tv);
        if (tw == w + 1) w2.push_back(tv);
        if (tw == w + 2) w3.push_back(tv);
        if (tw == w + 3) w4.push_back(tv);
    }
    sort(w1.begin(), w1.end(), greater<int>());
    sort(w2.begin(), w2.end(), greater<int>());
    sort(w3.begin(), w3.end(), greater<int>());
    sort(w4.begin(), w4.end(), greater<int>());

    int ans = 0;
    REP(i, w1.size() + 1)
    REP(j, w2.size() + 1)
    REP(k, w3.size() + 1)
    REP(l, w4.size() + 1) {
        if (w * i + (w + 1) * j + (w + 2) * k + (w + 3) * l > W) continue;

        int tans = 0;
        REP(m, i) tans += w1[m];
        REP(m, j) tans += w2[m];
        REP(m, k) tans += w3[m];
        REP(m, l) tans += w4[m];
        ans = max(ans, tans);
    }
    cout << ans << endl;

    return 0;
}