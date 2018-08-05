
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
char S[2005][2005];

using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> R[2005];
    vector<int> C[2005];

    REPS(i, N) {
        R[i].push_back(0);
        R[i].push_back(M + 1);
    }
    REPS(i, M) {
        C[i].push_back(0);
        C[i].push_back(N + 1);
    }
    REPS(i, N) {
        REPS(j, M) {
            char c;
            cin >> c;
            S[i][j] = c;
            if (S[i][j] == '#') {
                R[i].push_back(j);
                C[j].push_back(i);
            }
        }
    }
    REPS(i, N) {
        sort(R[i].begin(), R[i].end());
    }
    REPS(i, M) {
        sort(C[i].begin(), C[i].end());
    }

    int ans = 0;
    REPS(i, N) {
        REPS(j, M) {
            if (S[i][j] == '#') continue;
            // 右
            auto r = lower_bound(R[i].begin(), R[i].end(), j);
            // 下
            auto b = lower_bound(C[j].begin(), C[j].end(), i);
            int rnum = *r - j - 1;
            int lnum = j - *(r - 1) - 1;
            int bnum = *b - i - 1;
            int unum = i - *(b - 1) - 1;
            ans += rnum * unum + unum * lnum + lnum * bnum + bnum * rnum;
        }
    }
    cout << ans << endl;
    return 0;
}
