
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

bool is_biparate(const vector<vector<int>>& G, vector<int>& color) {
    queue<int> q;
    color.resize(G.size());
    color[0] = 1; // 0: undef, 1: black, 2: white
    REP(i, G[0].size()) {
        q.push(G[0][i]);
        color[G[0][i]] = 2;
    }

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        REP(i, G[p].size()) {
            int t = G[p][i];
            if (color[p] == color[t]) {
                return false;
            }
            if (color[t] != 0) continue;
            q.push(t);
            color[t] = color[p] == 1 ? 2 : 1;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color;
    if (is_biparate(G, color)) {
        int b = 0;
        int w = 0;
        REP(i, color.size()) {
            color[i] == 1 ? b++ : w++;
        }
        cout << b * w - M << endl;
    } else {
        int total = N * (N - 1) / 2;
        cout << total - M << endl;
    }
    return 0;
}
