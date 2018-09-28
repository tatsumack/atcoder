
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

typedef pair<int, int> P;

int N;
int x[20];
int c[20];
int v[20];

P item[20]; // v -> c


int dp[20][362144];

int f(int sold, int state) {
    if (dp[sold][state] >= 0) return dp[sold][state];
    if (sold == N) return 0;

    int money = x[sold];

    int cost = 0;
    int val = 0;
    REP(i, N) {
        if ((state >> i) & 1) continue;
        cost += c[i];
        val += v[i];
    }

    if (money >= cost) return val;

    int curval = 0;
    REP(i, N) {
        if ((state >> i) & 1) continue;
        curval = max(curval, f(sold, state | (1 << i)));
    }

    int nextval = INF;
    REP(i, N) {
        if ((state >> i) & 1) continue;
        nextval = min(nextval, f(sold + 1, state | (1 << i)));
    }

    return dp[sold][state] = max(curval, nextval);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    REP(i, N) {
        int X;
        cin >> X;
        x[i+1] = X + x[i];
    }
    REP(i, N) {
        cin >> c[i];
    }
    REP(i, N) {
        cin >> v[i];
    }

    CLR(dp, -1);

    cout << f(0, 0) << endl;

    return 0;
}
