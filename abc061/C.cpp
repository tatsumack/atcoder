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
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, K;
typedef pair<int, int> P;

signed main() {
    cin >> N >> K;

    vector<P> vp;
    REP(i, N) {
        P p;
        cin >> p.first >> p.second;
        vp.push_back(p);
    }
    sort(vp.begin(), vp.end());

    REP(i, N) {
        K -= vp[i].second;
        if (K <= 0) {
            cout << vp[i].first << endl;
            break;
        }
    }

    return 0;
}
