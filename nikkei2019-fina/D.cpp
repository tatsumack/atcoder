
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N, M;
    cin >> N >> M;

    vector<pair<pair<int, int>, int>> l;
    vector<int> t(M), r(M);
    REP(i, M) {
        int T, L, R;
        cin >> T >> L >> R;
        l.push_back({{L, -T}, i});
        t[i] = T;
        r[i] = R;
    }
    sort(l.begin(), l.end());

    priority_queue<P> pq;
    pq.push({0, N + 1});
    int h = 0;
    int pos = 0;
    int idx = 0;
    int res = 0;
    while (!pq.empty()) {
        while (!pq.empty() && pq.top().second < pos) {
            pq.pop();
        }
        if (pq.empty()) break;

        h = pq.top().first;
        int rr = pq.top().second + 1;
        while (idx < M && t[l[idx].second] <= h && l[idx].first.first <= rr) {
            pq.push({t[l[idx].second], r[l[idx].second]});
            idx++;
        }
        if (idx < M && l[idx].first.first <= rr) {
            rr = l[idx].first.first;
            pq.push({t[l[idx].second], r[l[idx].second]});
            idx++;
        }
        res += h * (rr - pos);
        pos = rr;
    }
    cout << res << endl;


    return 0;
}
