
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int len = 1;
    bool found = false;
    while (len*(len+1) / 2 <= N) {
        if (len*(len+1) / 2 == N) {
            found = true;
            break;
        }
        len++;
    }

    if (!found) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << len + 1 << endl;

    vector<vector<int>> ans(len+1);

    int cur = 1;
    REP(i, len) {
        FOR(j, i+1, len) {
            ans[i].push_back(cur);
            ans[j].push_back(cur);
            cur++;
        }
    }
    REP(i, len+1) {
        cout << ans[i].size() << " ";
        REP(j, ans[i].size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
