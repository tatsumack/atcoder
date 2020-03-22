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

typedef pair<int, int> P;


string common(string s1, string s2) {
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    REP(i, n) {
        REP(j, n) {
            if (s1[i] == s2[j] || (s1[i] == '?') || s2[j] == '?') {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = 0;
            }
        }
    }
    int len = 0;
    string res;
    REP(i, n) {
        if (dp[n][i] == i && len < dp[n][i]) {
            len = max(dp[n][i], len);
            res = s2.substr(0, len);
        }
    }
    return res;
}

class EThreeSubstrings {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        cout << common("abcdef", "defggg") << endl;
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int len = INF;
        {
            int tmp = 2 * n;
            string com = common(a,b);
            string cur;
            if (cur )
            cur = a + b.substr(com.size() - 1);
            cout << cur << endl;




        }
    }
};
