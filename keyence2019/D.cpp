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
#define fcout cout << fixed << setprecision(10)

using namespace std;

int mod = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    set<int> A, B;
    REP(i, N) {
        int a;
        cin >> a;
        A.insert(a);
    }
    REP(i, M) {
        int b;
        cin >> b;
        B.insert(b);
    }

    if (N != A.size()) {
        cout << 0 << endl;
        return 0;
    }
    if (M != B.size()) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    int empty = 0;
    int anum = 0;
    int bnum = 0;
    REV(i, N * M, 1) {
        if (A.count(i) > 0 && B.count(i) > 0) {
            anum++;
            bnum++;
            empty += (anum - 1) + (bnum - 1);
        } else if (A.count(i) > 0 && B.count(i) == 0) {
            anum++;
            empty += bnum;
            ans = (ans * bnum) % mod;
            empty--;
        } else if (B.count(i) > 0 && A.count(i) == 0) {
            bnum++;
            empty += anum;
            ans = (ans * anum) % mod;
            empty--;
        } else {
            ans = (ans * empty) % mod;
            empty--;
        }

        if (empty < 0) {
            break;
        }
    }

    if (empty !=  0 || ans <= 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
