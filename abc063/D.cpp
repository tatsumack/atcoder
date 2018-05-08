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

int N, A, B;
int H[100005];

int solve(int t) {
    int ans = 0;
    REP(i, N) {
        int hp = H[i] - B * t;
        if (hp <= 0) continue;
        ans += hp / (A - B);
        if (hp % (A - B) != 0) ans++;
    }
    return ans <= t;
}

signed main() {
    cin >> N >> A >> B;
    REP(i, N) cin >> H[i];
    int left = 0;
    int right = 2000000000;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (solve(mid))
            right = mid;
        else
            left = mid;
    }
    cout << right << endl;
    return 0;
}
