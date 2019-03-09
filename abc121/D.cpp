
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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int A, B;
    cin >> A >> B;

    int ans = 0;
    REV(i, 40, 1) {
        int a = A % (1LL << i);
        int b = B % (1LL << i);

        int half = 1LL << (i - 1LL);

        int num = 0;
        if (A / (1LL << i) != B / (1LL << i)) {
            if (b >= half) num += b - half + 1;
            num += (1LL << i) - max(a, half);
        } else {
            if (b >= half) {
                num = b - max(a, half) + 1;
            }
        }
        if (i == 1) {
            int a2 = A / 2;
            int b2 = B / 2;
            if (b2 > a2) {
                num += b2 - a2 - 1;
            }
        }
        if (num % 2 == 1) ans += 1LL << (i - 1);
    }
    cout << ans << endl;
    return 0;
}
