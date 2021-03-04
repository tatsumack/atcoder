#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class CStringInvasion {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> cnt(26);
        int res = 0;
        REP(i, s.size()) {
            int c = s[i] - 'a';
            cnt[c]++;
            if (i == 0) continue;
            if (s[i] == s[i - 1]) {
                res += (i + 1) - cnt[c];
                REP(j, 26) cnt[j] = 0;
                cnt[c] = i + 1;
            }
        }
        cout << res << endl;
    }
};
