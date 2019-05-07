
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

int H, W, N, sx, sy;
string S, T;

bool solve(int len, int pos, int type) {
    int left = 1;
    int right = len;
    char l = type == 0 ? 'L' : 'U';
    char r = type == 0 ? 'R' : 'D';
    REV(i, N - 1, 0) {
        if (T[i] == l) {
            right = min(right + 1, len);
        } else if (T[i] == r) {
            left = max(left - 1, 1LL);
        }
        if (S[i] == l) {
            left++;
        } else if (S[i] == r) {
            right--;
        }
        if (left > right) return false;
    }
    return left <= pos && pos <= right;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W >> N >> sx >> sy;
    cin >> S >> T;

    cout << (solve(W, sy, 0) && solve(H, sx, 1) ? "YES" : "NO") << endl;

    return 0;
}
