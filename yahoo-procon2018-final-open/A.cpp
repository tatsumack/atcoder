
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

typedef pair<int, int> P;

// 素因数
vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        s.push_back(i);
        while (a % i == 0) a /= i;
    }
    if (a > 1) s.push_back(a);
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<int, int> cnt;
    REP(i, N) {
        int a;
        cin >> a;

        auto facs = getPrimeFactors(a);
        REP(i, 1 << facs.size()) {
            int mul = 1;
            REP(j, facs.size()) {
                if (i >> j & 1) mul *= facs[j];
            }
            if (mul == 1) continue;
            cnt[mul]++;
        }
    }

    FOR(m, 1, M) {
        auto facs = getPrimeFactors(m);

        int ans = N;
        REP(i, 1 << facs.size()) {
            int mul = 1;
            REP(j, facs.size()) {
                if (i >> j & 1) mul *= facs[j];
            }
            bitset<100> bits(i);
            bits.count() % 2 == 1 ? ans -= cnt[mul] : ans += cnt[mul];
        }

        cout << ans << endl;
    }

    return 0;
}
