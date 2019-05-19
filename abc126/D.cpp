
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
#include <unordered_map>
#include <unordered_set>

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

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

typedef pair<int, int> P;

vector<P> G[100005];
vector<bool> visited;

P dfs(int p, int par) {

    int cost = -1;
    int res = -1;
    visited[p] = true;
    REP(i, G[p].size()) {
        auto e = G[p][i];
        int n = e.first;
        if (n == par) continue;
        if (visited[n]) continue;
        auto kv = dfs(n, p);
        if (kv.first + e.second > cost) {
            cost = kv.first + e.second;
            res = kv.second;
        }
    }

    return {cost, res};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    REP(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    visited.resize(N);
    REP(i, N) visited[i] = false;

    //auto kv = dfs(0, -1);
    int s = 0;

    vector<int> res(N, -1);
    queue<P> q;
    q.push({s, 0});
    while (!q.empty()) {
        auto kv = q.front();
        q.pop();
        int cur = kv.first;
        int col = kv.second;
        if (res[cur] >= 0) continue;
        res[cur] = col;
        REP(i, G[cur].size()) {
            auto e = G[cur][i];
            if (e.second % 2 == 0) {
                q.push({e.first, col});
            }
            else {
                q.push({e.first, col ^ 1});
            }
        }

    }

    REP(i, N) cout << res[i] << endl;


    return 0;
}
