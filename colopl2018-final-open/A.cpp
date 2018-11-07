
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

    int N;
    cin >> N;
    string S;
    cin >> S;

    bool hasB = false;
    int fb = -1;
    REP(i, S.size()) {
        if (S[i] == 'B') {
            if (fb == -1) fb = i;
            hasB = true;
        }
    }

    if (!hasB) {
        cout << S.size() * N * (1 + S.size() * N) / 2 << endl;
        return 0;
    }

    if (N == 1) {
        int cur = 0;
        int ans = 0;
        REP(i, S.size()) {
            char c = S[i];
            if (c == 'A') {
                cur++;
                ans += cur;
            } else {
                cur = 0;
            }
        }
        cout << ans << endl;
        return 0;
    }

    int front = 0;
    int back = 0;
    int middle = 0;
    int cur = 0;
    REP(i, S.size() * 2) {
        char c = S[i % S.size()];
        if (c == 'A') {
            cur++;
            if (i < fb) {
                front += cur;
            } else if (i < fb + S.size()) {
                middle += cur;
            } else {
                back += cur;
            }
        } else {
            cur = 0;
        }
    }

    cout << front + back + (N - 1) * middle << endl;

    return 0;
}
