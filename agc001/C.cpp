
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


int N, K;
vector<int> G[2005];

int f(int s) {
    map<int, int> dmap;
    dmap[s] = 0;

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        REP(i, G[t].size()) {
            int k = G[t][i];
            if (dmap.count(k) > 0) continue;
            dmap[k] = dmap[t] + 1;
            q.push(k);
        }
    }

    int res = 0;
    for (auto kv : dmap) {
        if (kv.second > K / 2) res++;
    }

    return res;
}

int g(pair<int, int> s) {
    map<int, int> dmap;
    dmap[s.first] = 0;
    dmap[s.second] = 0;

    queue<int> q;
    q.push(s.first);
    q.push(s.second);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        REP(i, G[t].size()) {
            int k = G[t][i];
            if (dmap.count(k) > 0) continue;
            dmap[k] = dmap[t] + 1;
            q.push(k);
        }
    }

    int res = 0;
    for (auto kv : dmap) {
        if (kv.second > (K - 1) / 2) res++;
    }

    return res;


}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    vector<pair<int, int>> edge;
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge.push_back({a, b});
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = INF;
    if (K % 2 == 0) {
        REP(i, N) {
            ans = min(ans, f(i));
        }
    } else {
        REP(i, edge.size()) {
            ans = min(ans, g(edge[i]));
        }
    }

    cout << ans << endl;

    return 0;
}
