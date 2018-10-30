
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

    int n;
    cin >> n;


    vector<int> cnt(26);

    REP(i, n) {
        string s;
        cin >> s;


        vector<int> tmp(26);
        REP(j, s.size()) {
            if (i == 0) {
                cnt[s[j] - 'a']++;
                continue;
            }
            tmp[s[j] - 'a']++;
        }
        if (i == 0) continue;
        REP(j, cnt.size()) {
            cnt[j] = min(tmp[j], cnt[j]);
        }
    }

    string ans;
    REP(i, cnt.size()) {
        REP(j, cnt[i]) {
            ans += (char) ('a' + i);
        }
    }
    cout << ans << endl;

    return 0;
}
