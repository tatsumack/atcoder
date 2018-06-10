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

int K, N;
string v[51], w[51];

void dfs(int n, int num, int cur, vector<string>& S) {
    if (n == N) {
        REP(i, N) {
            string s;
            REP(j, v[i].size()) {
                int t = v[i][j] - '0';
                s += S[t];
            }
            if (s != w[i]) return;
        }
        REP(i, K) { cout << S[i + 1] << endl; }
        exit(0);
    } else {
        if (num >= v[n].size()) return;
        FOR(i, 1, 3) {
            if (cur + i > w[n].size()) continue;

            int p = v[n][num] - '0';
            string s = w[n].substr(cur, i);
            if (!S[p].empty() && S[p] != s) continue;

            string old = S[p];
            if (cur + i < w[n].size()) {
                S[p] = s;
                dfs(n, num + 1, cur + i, S);
            } else {
                if (num + 1 != v[n].size()) continue;
                S[p] = s;
                dfs(n + 1, 0, 0, S);
            }
            S[p] = old;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    REP(i, N) { cin >> v[i] >> w[i]; }

    vector<string> S;
    S.resize(K + 1);
    dfs(0, 0, 0, S);
    return 0;
}
