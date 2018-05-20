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

int fac[100005];
int rev[100005];

int C[51][51];  // C[n][k] -> nCk

void comb_table(int N) {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 or j == i) {
                C[i][j] = 1LL;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
            }
        }
    }
}

int N, A, B;
signed main() {
    cin >> N >> A >> B;

    map<int, int> count;
    vector<int> v(N);
    REP(i, N) {
        cin >> v[i];
        count[v[i]]++;
    }
    sort(v.begin(), v.end(), greater<int>());

    set<int> s;

    map<int, int> rest;
    int ans = 0;
    int last = 0;
    int r = A;
    REP(i, A) {
        ans += v[i];
        last = v[i];
        rest[v[i]]++;
    }
    printf("%.6f\n", (double)ans / A);

    comb_table(50);

    int ways = 0;
    if (v[0] != last) {
        ways = C[count[last]][rest[last]];
    } else {
        FOR(r, rest[last], min(rest[last] + B - A, count[last]) + 1) {
            ways += C[count[last]][r];
        }
    }
    cout << ways << endl;

    return 0;
}
