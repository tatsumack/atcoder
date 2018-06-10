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

int N, A, B[100005];
string K;

map<int, int> m;
int ls = 0;
int lb = 0;

void dfs(int n, int size) {
    int next = B[n];
    if (m[next] != 0) {
        ls = size - m[next] + 1;
        lb = m[next] - 1;
        return;
    }
    m[next] = size + 1;
    dfs(next, size + 1);
}

int solve(int n, int count, int lim) {
    int next = B[n];
    if (count + 1 == lim) return next;
    return solve(next, count + 1, lim);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A;
    cin >> K;
    REPS(i, N) { cin >> B[i]; }

    m[A] = 0;
    dfs(A, 0);
    if (K.size() <= 6 && stoi(K) <= ls) {
        cout << solve(A, 0, stoi(K)) << endl;
    } else {
        int c = 0;
        REP(i, K.size()) { c = (c * 10 + (K[i] - '0')) % ls; }
        while (c < lb) c += ls;
        if (c == 0) c += ls;
        cout << solve(A, 0, c) << endl;
    }

    return 0;
}
