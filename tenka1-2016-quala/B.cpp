
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

vector<int> C(1005, -1);
vector<vector<int>> child(1005);
int solve(int n) {
    if (C[n] > 0) return C[n];

    int t = INF;
    REP(i, child[n].size())
    {
        t = min(solve(child[n][i]), t);
    }
    if (n == 0) {
        return 0;
    }
    REP(i, child[n].size())
    {
        C[child[n][i]] = C[child[n][i]] - t;
    }

    return C[n] = t;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    FOR(i, 1, N-1) {
        int p;
        cin >> p;
        child[p].push_back(i);
    }

    REP(i, M) {
        int b, cc;
        cin >> b >> cc;
        C[b] = cc;
    }

    solve(0);

    int ans = 0;
    REP(i, N)  {
        if (i == 0) continue;
        ans += C[i];
    }
    cout << ans << endl;


    return 0;
}
