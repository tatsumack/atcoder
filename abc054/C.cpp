
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

int N, M;
bool visit[10];
int ans;
vector<vector<bool>> G(10, vector<bool>(10));

void dfs(int n) {

    bool ok = true;
    REP(i, N) {
        if (!visit[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        ans++;
        return;
    }

    REP(i, G[n].size()) {
        if (!G[n][i]) continue;
        if (visit[i]) continue;
        visit[i] = true;
        dfs(i);
        visit[i] = false;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = true;
        G[b][a] = true;
    }

    ans = 0;
    visit[0] = true;
    dfs(0);
    cout << ans << endl;

    return 0;
}
