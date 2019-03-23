
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> b(N);
    REP(i, N) cin >> b[i];

    int bn = b.size();
    vector<int> ans;
    REV(i, N - 1, 0) {
        bool found = false;
        int target = -1;
        REV(j, bn - 1, 0) {
            if (!found && j + 1 == b[j]) {
                found = true;
                ans.push_back(b[j]);
                target = j;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
            return 0;
        }

        bn--;
        REP(j, bn) {
            if (j < target) continue;
            b[j] = b[j + 1];
        }
    }

    reverse(ans.begin(), ans.end());

    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}
