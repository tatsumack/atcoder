
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

// 素因数
vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        while (a % i == 0) {
            a /= i;
            s.push_back(i);
        }
    }
    if (a > 1) {
        s.push_back(a);
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> pf;
    FOR(i, 1, N) {
        auto v = getPrimeFactors(i);
        REP(i, v.size()) {
            pf[v[i]]++;
        }
    }

    set<int> overthree;
    set<int> overfive;
    set<int> overfifteen;
    set<int> overtwentyfive;
    set<int> overseventyfive;
    for (auto kv : pf) {
        if (kv.second + 1 >= 3) {
            overthree.insert(kv.first);
        }
        if (kv.second + 1 >= 5) {
            overfive.insert(kv.first);
        }
        if (kv.second + 1 >= 15) {
            overfifteen.insert(kv.first);
        }
        if (kv.second + 1 >= 25) {
            overtwentyfive.insert(kv.first);
        }
        if (kv.second + 1 >= 75) {
            overseventyfive.insert(kv.first);
        }
    }

    int ans = overseventyfive.size();

    for (auto t: overtwentyfive) {
        int n = overthree.size() - 1;
        if (n < 0) continue;
        ans += n;
    }

    for (auto t: overfifteen) {
        int n = overfive.size() - 1;
        if (n < 0) continue;
        ans += n;
    }

    for (auto t : overthree) {
        int n = overfive.count(t) > 0 ? overfive.size() - 1 : overfive.size();
        if (n < 1) continue;
        ans += n * (n - 1) / 2;
    }
    cout << ans << endl;


    return 0;
}
