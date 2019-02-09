
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

    int K, A, B;
    cin >> K >> A >> B;

    if (B - A < 2LL) {
        cout << K + 1LL << endl;
        return 0;
    }

    int ans = 0;

    // 最初の1枚
    {
        int need = A - 1LL;
        need++; // 1円
        need++; // B枚に返る
        if (need > K) {
            cout << K + 1LL << endl;
            return 0;
        }

        if (B > need + 1LL) {
            ans = B;
        } else {
            ans = need + 1LL;
        }
        K -= need;
    }

    int num = K / 2LL;
    ans += (B-A) * num;
    K -= num * 2;
    ans += K;
    cout << ans << endl;


    return 0;
}
