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

string s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    vector<int> pos(s.size());
    vector<int> neg(s.size());

    REP(i, s.size()) {
        if (i > 0) {
            pos[i] = pos[i - 1];
            neg[i] = neg[i - 1];
        }

        if (s[i] == '+') pos[i]++;
        if (s[i] == '-') neg[i]++;
    }

    vector<pair<int, int> > va;
    REP(i, s.size()) {
        if (s[i] == 'M') {
            int p = pos[s.size() - 1] - pos[i];
            int n = neg[s.size() - 1] - neg[i];
            va.push_back({p - n, n - p});
        }
    }
    sort(va.begin(), va.end());

    int ans = 0;
    REP(i, va.size()) {
        if (i < va.size() / 2) {
            ans += va[i].second;
        } else {
            ans += va[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
