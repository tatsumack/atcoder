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

class ATwoChoices {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        map<int, int> cnt;
        int res = 0;
        REP(i, N) {
            string s;
            cin >> s;

            int val = 0;
            for (auto c : s) {
                int n = c - '0';
                val ^= n;
            }
            res += cnt[val ^ 1];
            cnt[val]++;
        }
        cout << res << endl;
    }
};
