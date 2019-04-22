
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

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> b(N + 1);
    vector<int> w(N + 1);
    REP(i, N) {
        if (S[i] == '#') {
            b[i + 1] = b[i] + 1;
        }
        else {
            b[i + 1] = b[i];
        }
    }

    REV(i, N, 1) {
        w[i-1] = w[i];
        if (S[i] == '.') w[i-1]++;
    }

    int res = INF;
    REP(i, N + 1) {
        res = min(res, w[i] + b[i]);
    }

    cout << res << endl;

    return 0;
}
