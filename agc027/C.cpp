
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string s;
    cin >> s;


    vector<vector<int>> edge(N);
    vector<int> A(N, false);
    vector<int> B(N, false);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        s[a] == 'A' ? A[b]++ : B[b]++;
        s[b] == 'A' ? A[a]++ : B[a]++;
    }

    vector<bool> ok(N);
    queue<int> d;
    REP(i, N) {
        if (A[i] == 0 || B[i] == 0) {
            d.push(i);
            ok[i] = false;
        }
        else {
            ok[i] = true;
        }
    }

    while (!d.empty()) {
        int cur = d.front(); d.pop();

        REP(i, edge[cur].size()) {
            int t = edge[cur][i];
            if (!ok[t]) continue;

            s[cur] == 'A' ? A[t]-- : B[t]--;

            if (A[t] == 0 || B[t] == 0) {
                d.push(t);
                ok[t] = false;
            }
        }
    }

    REP(i, N) {
        if (!ok[i]) continue;

        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
