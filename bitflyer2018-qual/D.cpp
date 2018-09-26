
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

    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<string> A(N);
    REP(i, N) cin >> A[i];

    int h = min(H, 2 * N + 1);
    int w = min(W, 2 * M + 1);

    vector<vector<int>> b(h, vector<int>(w, 0));

    // imos
    REP(i, N) {
        REP(j, A[i].size()) {
            char c = A[i][j];
            if (c == '.') continue;
            b[i][j] += 1;
            if (i < N - 1) b[h - (N - i) + 1][j] += -1;
            if (j < M - 1) b[i][w - (M - j) + 1] += -1;
            if (i < N - 1 && j < M - 1) b[h - (N - i) + 1][w - (M - j) + 1] += 1;
        }
    }
    REP(j, w - 1) REP(i, h) {
            b[i][j + 1] += b[i][j];
        }
    REP(i, h - 1) REP(j, w) {
        b[i + 1][j] += b[i][j];
    }

    int ans = 0;
    REP(i, h) REP(j, w) {
        if (b[i][j] == 0) continue;
        int tmp = 1;
        if (i == N && H > 2 * N + 1) {
            tmp *= H - 2 * N;
        }
        if (j == M && W > 2 * M + 1) {
            tmp *= W - 2 * M;
        }
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}
