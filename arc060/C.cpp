
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    REP(i, N) cin >> x[i];
    sort(x.begin(), x.end());

    int s = -1;
    int d = INF;
    REP(i, N) {
        x[i] = A - x[i];
        if (abs(x[i] < d)) {
            d = abs(x[i]);
            s = i;
        }
    }

    int l = s;
    int r = s;
    int sum = x[s];
    int ans = 0;
    while (l >= 0 && r < N) {
        if (sum == 0) {
            ans++;
            if (l > 0) {
                l--;
                sum += x[l];
            }
            else if (r < N){
                r++;
                sum += x[r];
            }
            else {
                break;
            }

        }

        if (sum < 0) {
            if (l == 0) break;
            l--;
            sum += x[l];
        }
        else {
            if (r == N-1) break;
            r++;
            sum += x[r];
        }
    }
    cout << ans << endl;

    return 0;
}
