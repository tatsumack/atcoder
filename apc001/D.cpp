
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

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;

    UnionFind(int size) : par(size), rank(size), vsize(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        vsize[x] += vsize[y];
        vsize[y] = vsize[x];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int getSize(int x) { return vsize[find(x)]; }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;


    vector<int> a(N);
    REP(i, N) cin >> a[i];

    UnionFind uf(N);
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    if (M == N - 1) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<int, priority_queue<P, vector<P>, greater<P>>> pqs;
    vector<P> v;
    REP(i, N) {
        int par = uf.find(i);
        pqs[par].push({a[i], i});
        v.emplace_back(a[i], i);
    }

    int g = pqs.size();
    if (2 * (g - 1) > N) {
        cout << "Impossible" << endl;
        return 0;
    }

    int res = 0;
    vector<bool> used(N);
    for (auto& kv : pqs) {
        auto& pq = kv.second;
        res += pq.top().first;
        used[pq.top().second] = true;
    }

    int cnt = g;
    sort(v.begin(), v.end());
    REP(i, N) {
        int t = v[i].second;
        if (used[t]) continue;
        if (cnt == 2 * (g - 1)) break;
        res += v[i].first;
        cnt++;
    }

    cout << res << endl;

    return 0;
}
