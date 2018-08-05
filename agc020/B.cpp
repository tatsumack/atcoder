
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> K;
    vector<int> A(K);
    REP(i, K) cin >> A[i];
    reverse(A.begin(), A.end());

    if (A[0] != 2) {
        cout << -1 << endl;
        return 0;
    }

    int mina = 2;
    REP(i, K) {
        int l = mina;
        int r = mina + A[i];
        if (i == K - 1) {
            mina = mina;
        } else {
            if (l % A[i + 1] == 0) l--;
            int tmp = (l / A[i + 1] + 1) * A[i + 1];
            if (tmp >= r) {
                mina = -1;
                break;
            }
            mina = tmp;
        }
    }

    int maxa = 2;
    REP(i, K) {
        int l = maxa;
        int r = maxa + A[i];
        if (i == K - 1) {
            maxa = r - 1;
        } else {
            if (r % A[i + 1] == 0) r--;

            int tmp = r / A[i + 1] * A[i + 1];
            if (tmp < l) {
                cout << -1 << endl;
                return 0;
            }
            maxa = tmp;
        }
    }

    cout << mina << " " << maxa << endl;

    return 0;
}
