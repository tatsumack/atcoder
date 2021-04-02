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

class CLargeRPSTournament {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char, map<char, int>> m;
        m['R']['R'] = 0;
        m['R']['P'] = 1;
        m['R']['S'] = 0;
        m['P']['R'] = 0;
        m['P']['P'] = 0;
        m['P']['S'] = 1;
        m['S']['R'] = 1;
        m['S']['P'] = 0;
        m['S']['S'] = 0;
        while (k--) {
            string next = "";
            s += s;
            for (int i = 0; i < s.size(); i += 2) {
                int ni = m[s[i]][s[i + 1]] + i;
                next += s[ni];
            }
            swap(next, s);
        }
        cout << s[0] << endl;
    }
};
