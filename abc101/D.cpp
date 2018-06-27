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
#define INF (LLONG_MAX - 1e5)

using namespace std;

int K;

double sunuke(int n) {
    double res = 0;

    int t = n;
    while (n > 0) {
        res += (n % 10);
        n /= 10;
    }
    return (double)t / res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    int d = 1;
    int prev = 1;
    REPS(i, K) {
        if (i == 1) {
            cout << prev << endl;
            continue;
        }
        double a = sunuke(prev + d);
        double b = INF;
        int cnt = 0;
        while (a > b) {
            cnt++;
            b = sunuke(a + d * cnt);
        }
        d *= cnt;
        prev = b;
        cout << b << endl;
    }

    return 0;
}
