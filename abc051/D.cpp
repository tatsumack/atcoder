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
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, M, A[105], B[105], C[105], d[105][105], pre[105][105], used[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    REPS(i, N) REPS(j, N) {
        d[i][j] = INF;
        used[i][j] = 1;
    }

    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
        used[a][b] = 0;
        used[b][a] = 0;
        pre[a][b] = a;
        pre[b][a] = b;
    }

    REPS(k, N) REPS(i, N) REPS(j, N) {
        if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
            pre[i][j] = pre[k][j];
        }
    }

    set<int> s;
    REPS(i, N) REPS(j, N) {
        for (int k = j; k != i; k = pre[i][k]) {
            int pk = pre[i][k];
            used[k][pk] = 1;
            used[pk][k] = 1;
        }
    }
    int ans = 0;
    REPS(i, N) REPS(j, N) {
        if (used[i][j] == 0) {
            ans++;
        }
    }
    cout << ans / 2 << endl;

    return 0;
}
