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
#define INF (LLONG_MAX - 1e5)

using namespace std;

typedef pair<int, int> P;

int N, M;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<pair<int, P> > p(M);
    REP(i, M) {
        int a, b;
        cin >> a >> b;

        p[i] = {b - a, {a, b}};
    }
    sort(p.begin(), p.end());

    set<int> v;
    v.insert(0);
    v.insert(N);
    REP(i, M) {
        auto kv = p[i].second;
        int a = kv.first;
        int b = kv.second;

        auto aitr = v.lower_bound(a);
        auto bitr = v.lower_bound(b);
        if (aitr == bitr) {
            v.insert(b - 1);
        }
    }

    cout << v.size() - 2 << endl;

    return 0;
}
