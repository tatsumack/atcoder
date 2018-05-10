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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

struct Edge {
    int from, to, cost;
    Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost){};
    Edge(){};
};

Edge es[2005];

int d[1005];
int V, E;

bool shortest_path(int s) {
    REPS(i, V) d[i] = INF;
    d[s] = 0;

    int loop = 0;
    while (true) {
        ++loop;
        bool update = false;
        REP(i, E) {
            Edge& e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (loop >= V && e.to == V) {
                    // find negative loop
                    return false;
                }
                if (loop >= V * 2) {
                    return true;
                }
                update = true;
            }
        }
        if (!update) break;
    }
    return true;
}

signed main() {
    cin >> V >> E;
    REP(i, E) {
        int a, b, c;
        cin >> a >> b >> c;
        Edge e(a, b, -c);
        es[i] = e;
    }
    if (shortest_path(1)) {
        cout << -d[V] << endl;
    } else {
        cout << "inf" << endl;
    }

    return 0;
}
