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

class ELucky7Battle {
public:
    int N;
    string S, X;
    vector<int> v;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> S >> X;
        vector<bool> dp(7);
        dp[0] = true;
        for (int i = S.size() - 1; i >= 0; i--) {
            int c = S[i] - '0';
            vector<bool> next(7);
            if (X[i] == 'T') {
                REP(j, 7) {
                    int n1 = (j * 10) % 7;
                    int n2 = (j * 10 + c) % 7;
                    if (dp[n1] || dp[n2]) next[j] = true;
                }
            } else {
                REP(j, 7) {
                    int n1 = (j * 10) % 7;
                    int n2 = (j * 10 + c) % 7;
                    if (dp[n1] && dp[n2]) next[j] = true;
                }
            }
            dp = next;
        }
        cout << (dp[0] ? "Takahashi" : "Aoki") << endl;
    }
};
