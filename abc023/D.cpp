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
#define INF (3e15)

using namespace std;

int N, H[100005], S[100005];

bool check(int h) {
    vector<double> v(N);
    REP(i, N) { v[i] = (double)(h - H[i]) / S[i]; }
    sort(v.begin(), v.end());
    REP(i, N) {
        if (i > v[i]) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int maxH = 0;
    int maxS = 0;
    REP(i, N) {
        cin >> H[i] >> S[i];
        maxH = max(maxH, H[i]);
        maxS = max(maxS, S[i]);
    }

    int l = 0;
    int r = maxH + maxS * N + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        check(m) ? r = m : l = m;
    }
    cout << r << endl;

    return 0;
}
