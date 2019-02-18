
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
int N, M;
int A[10];

string dp[10005];

map<int, int> mp = {
        {1, 2},
        {2, 5},
        {3, 5},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 3},
        {8, 7},
        {9, 6},
};

string solve(int n) {
    if (dp[n] != "") return dp[n];
    if (n == 0) return "";

    string res = "";
    REP(i, M) {
        int a = A[i];
        if (n - mp[a] < 0) continue;
        string r = solve(n - mp[a]);
        if (r == "0") {
            continue;
        }

        char r0 = r[0];

        string tmp;
        if (a >= r[0] - '0') {
            tmp = to_string(a) + r;
        }
        else {
            tmp = r + to_string(a);
        }

        if (tmp.size() >= res.size()) {
            res = tmp;
        }

    }

    if (res.empty()) res = "0";

    dp[n] = res;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    REP(i, M) cin >> A[i];
    sort(A, A + M);

    string ans = solve(N);
    cout << ans << endl;
}
