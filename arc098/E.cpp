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
#define INF (3e15)

using namespace std;

int N, A[2005], K, Q;
int smin[2005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> Q;
    REP(i, N) cin >> A[i];

    int ans = INF;
    REP(mini, N) {
        vector<int> v[N + 1];
        int vi = 0;
        REP(i, N) {
            if (A[i] < A[mini]) {
                vi++;
                continue;
            }
            v[vi].push_back(A[i]);
        }
        vector<int> sv;
        REP(i, vi + 1) {
            if (v[i].size() < K + Q - 1) continue;
            sort(v[i].begin(), v[i].end());
            REP(j, Q) { sv.push_back(v[i][j]); }
        }
        if (sv.size() < Q) continue;
        sort(sv.begin(), sv.end());
        ans = min(ans, sv[Q - 1] - A[mini]);
    }
    cout << ans << endl;

    return 0;
}
