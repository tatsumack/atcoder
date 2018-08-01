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

int N, K, A[100005];
string S[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    set<int> set;
    REP(i, K) {
        int a;
        cin >> a;
        set.insert(a);
    }

    vector<string> ok;
    vector<string> ng;
    FOR(i, 1, N) {
        string s;
        cin >> s;
        if (set.count(i) > 0) {
            ok.push_back(s);
        } else {
            ng.push_back(s);
        }
    }
    sort(ok.begin(), ok.end());
    sort(ng.begin(), ng.end());

    string ans;
    REP(i, ok[0].size()) {
        auto itr = lower_bound(ng.begin(), ng.end(), ans);
        if (itr == ng.end() || (*itr).find(ans) != 0) {
            break;
        }
        if (ok[0][i] == ok[ok.size() - 1][i]) {
            ans += ok[0][i];
        } else {
            break;
        }
    }

    REP(i, ng.size()) {
        if (ng[i].find(ans) == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
