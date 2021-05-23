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

class B180 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        string res;
        REP(i, s.size()) {
            if (s[i] == '6') {
                res += '9';
                continue;
            }
            if (s[i] == '9') {
                res += '6';
                continue;
            }
            res += s[i];
        }
        cout << res << endl;
    }
};
